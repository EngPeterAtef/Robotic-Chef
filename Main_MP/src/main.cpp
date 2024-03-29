#include "def.h"

//------------------------

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Wire.begin(); // join i2c bus as a Master // i2c pins are connected to D15 and D16
    mybluetooth.begin(9600);
    pinMode(direction_pin, OUTPUT);
    pinMode(step_pin, OUTPUT);
    pinMode(stepper_enable_pin, OUTPUT);
    pinMode(dc1_pin, OUTPUT);
    pinMode(dc2_pin, OUTPUT);

    pinMode(pumpPin, OUTPUT);
    pinMode(boiler_pin, OUTPUT);
    pinMode(heater_pin,OUTPUT);

}

void loop() {

    // Blocking Receive
    // recipeID is send by referece
    // bytes are unsigned data type

    receive();
    byte recipeID = quantities[0];
    Wire.beginTransmission(7); // transmit to device #7
    Wire.write(recipeID);      // sends one byte to the other arduino
    Wire.endTransmission();    // stop transmitting

    /**
     *  it will send the ID to the other arduino so that it starts its job too
     * NOTE: we can use a pipe to sync the actions between the 2 arduinos
     *
     */

    recipes_func[recipeID - 1](); // Call The corresponding recipe function (assumed ID startes with 1)
}

// Function to receive the recipeID from the user and depends on this id it will take number of specific variables
void receive() {
    bool finishedReading = false;
    byte i = 0;

    while (!finishedReading) {
        while (mybluetooth.available() > 0) {
            byte dataRead = mybluetooth.read();

            if (dataRead != endOfLine) {
                quantities[i] = dataRead;
                i++;
            } else {
                finishedReading = true;
                break; // wont break till all message has been read
            }
        }
    }
}

// function pump that takes the quantity of required water
void pump(int amountWater) {
    // control the relay to be high during droping time depends on the amount of water sent
    digitalWrite(pumpPin, HIGH);
    delay(amountWater * 100);
    digitalWrite(pumpPin, LOW);
}


/**
 *
 * @param gate_angle  angle of the gate we're heading to
 * @param for_how_long  responsible for different types of ingredients, some require it small or big amount of time
 */
void open_gate(unsigned short gate_angle, unsigned short for_how_long = 8000) {

    //!NOTE: steps are just an integer anyway -> why Float
    //!NOTE: gate_angle can be a zero 3ady -- gate at the starting position

    digitalWrite(stepper_enable_pin, HIGH);
    Serial.println(gate_angle);

    auto steps = (short) (gate_angle / stepPerAngle);
    digitalWrite(direction_pin, HIGH);
    for (int i = 0; i < steps; i++) {

        // To execute a step (or in this case , a micro step), toggle the step_pin HIGH/LOW
        // you can control the speed by the amount of delay you insert in the toggle
        digitalWrite(step_pin, HIGH);
        delay(10);     // use delayMicroseconds instead of "delay" in order to make motor move faster

        // there is processing and mechanical limit on the value of the delay
        digitalWrite(step_pin, LOW);
        delay(10);

    }

    //dc motor
    digitalWrite(dc1_pin, LOW);
    digitalWrite(dc2_pin, HIGH);
    delay(for_how_long);
    digitalWrite(dc1_pin, HIGH);
    digitalWrite(dc2_pin, LOW);

    delay(for_how_long);

    digitalWrite(dc1_pin, LOW);
    digitalWrite(dc2_pin, LOW);
    //TODO: Consider that amount of time
    delay(2000);

    digitalWrite(direction_pin, LOW); // spin in the opposite direction
    for (int i = 0; i < steps; i++) {
        // To execute a step (or in this case , a micro step), toggle the step_pin HIGH/LOW
        digitalWrite(step_pin, HIGH);
        delay(10);
        digitalWrite(step_pin, LOW);
        delay(10);
    }
}


/**
 * @recipe  TEA
 */
void recipe1() {
    byte tea_q = quantities[1];
    byte sugar_q = quantities[2];

    digitalWrite(boiler_pin, HIGH);

    // we might need some repetitions for this
    //for fine ingredients like tea -> we should open and close the gate
    // multiple times
    for (byte i = 0; i < tea_q; i++)
        open_gate(TEA_GATE, 2000);

    for (byte i = 0; i < sugar_q; i++)
        open_gate(SUGAR_GATE, 2000);

    delay(5000); // for the water to be sure it boiled

    digitalWrite(boiler_pin, LOW);
    // get the water out of the heater Now
    // TODO: NEED TO TEST THESE numbers in reality
    pump(3);

    Serial.println("\nta ta tea\n");
}

void recipe2() {
    byte pasta_q = quantities[1];
    byte salt_q = quantities[2];
    byte pepper_q = quantities[3];
    
    digitalWrite(boiler_pin, HIGH);

    delay(5000); //for the water to be sure it boiled

    digitalWrite(boiler_pin, LOW);
    // get the water out of the heater Now
    // TODO: NEED TO TEST THESE numbers in reality
    pump(6); 
    digitalWrite(heater_pin,HIGH);
    
    open_gate(PASTA_GATE,2000*pasta_q);

    delay(500000); //for the pasta to cook
    digitalWrite(heater_pin, LOW); 

    //drain pasta 
    delay(5000); //to make sure that it got drained

    for(byte i =0;i < salt_q; i++)
    open_gate(SALT_GATE,2000);

    for(byte i =0;i < pepper_q; i++)
    open_gate(PEPPER_GATE,2000);

    Serial.println("\nmacarona\n");
}

void recipe3() {
   byte popcorn_q = quantities[1]; 
   byte salt_q = quantities[2];

   digitalWrite(heater_pin,HIGH);

   open_gate(POPCORN_GATE,2000*popcorn_q);

   delay(500000); //for popcorn to cook

   digitalWrite(heater_pin, LOW);

    delay(5000); //to get it ready

   for(byte i =0;i < salt_q; i++)
    open_gate(SALT_GATE,2000);

    Serial.println("\npopcorn\n");
}

void recipe4() {
    byte peas_q = quantities[1];
    byte carrots_q = quantities[2];
    byte kosa_q = quantities[3];
    byte salt_q = quantities[4];
    byte pepper_q = quantities[5];

    digitalWrite(heater_pin,HIGH);
    digitalWrite(boiler_pin, HIGH);

    open_gate(PEAS_GATE,2000*peas_q);
    open_gate(CARROTS_GATE,2000*carrots_q);
    open_gate(KOSA_GATE,2000*kosa_q);

    for(byte i =0;i < salt_q; i++)
    open_gate(SALT_GATE,2000);

    for(byte i =0;i < pepper_q; i++)
    open_gate(PEPPER_GATE,2000);

    delay(5000); // for the water to be sure it boiled

    digitalWrite(boiler_pin, LOW);

    pump(4);

    delay(1200000); //20 min to cook

    digitalWrite(heater_pin,LOW);

    Serial.println("\nsaute\n");
}

void recipe5() {
    byte onion_q = quantities[1];
    byte salt_q = quantities[2];
    byte pepper_q = quantities[3];
    byte chicken_q = quantities[4];
    byte bellpepper_q = quantities[5];

    digitalWrite(heater_pin,HIGH);
    
    open_gate(ONION_GATE,2000*onion_q);

    for(byte i =0;i < salt_q; i++)
    open_gate(SALT_GATE,2000);

    for(byte i =0;i < pepper_q; i++)
    open_gate(PEPPER_GATE,2000);
    delay(180000);

    open_gate(CHICKEN_GATE,2000*chicken_q);
    delay(300000);

    open_gate(BELLPEPPER_GATE,2000*bellpepper_q);
    delay(6000); 

    digitalWrite(heater_pin,LOW);

    Serial.println("\nshawrma\n");
}
