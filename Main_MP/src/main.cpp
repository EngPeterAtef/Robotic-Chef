//#include "def.h"
//
////------------------------
//
//void setup() {
//    // put your setup code here, to run once:
//    Serial.begin(9600);
//    Wire.begin(); // join i2c bus as a Master // i2c pins are connected to D15 and D16
//    mybluetooth.begin(9600);
//}
//
//void loop() {
//
//    // Blocking Receive
//    // recipeID is send by referece
//    // bytes are unsigned data type
//
//    receive();
//    byte recipeID = quantities[0];
//    Wire.beginTransmission(7); // transmit to device #7
//    Wire.write(recipeID);      // sends one byte to the other arduino
//    Wire.endTransmission();    // stop transmitting
//
//    /**
//     *  it will send the ID to the other arduino so that it starts its job too
//     * NOTE: we can use a pipe to sync the actions between the 2 arduinos
//     *
//     */
//
//    recipes_func[recipeID - 1](); // Call The corresponding recipe function (assumed ID startes with 1)
//}
//
//// Function to receive the recipeID from the user and depends on this id it will take number of specific variables
//void receive() {
//    bool finishedReading = false;
//    byte i = 0;
//
//    while (!finishedReading) {
//        while (mybluetooth.available() > 0) {
//            byte dataRead = mybluetooth.read();
//
//            if (dataRead != endOfLine) {
//                quantities[i] = dataRead;
//                i++;
//            } else {
//                finishedReading = true;
//                break; // wont break till all message has been read
//            }
//        }
//    }
//}
//
//// function pump that takes the quantity of required water
//void pump(int amountWater) {
//    // control the relay to be high during droping time depends on the amount of water sent
//    digitalWrite(pipePin, HIGH);
//    delay(amountWater * 100);
//    digitalWrite(pipePin, LOW);
//}
//
//// opens heater if closed or close it if open
//void inline open_close_heater() {
//    digitalWrite(heaterPin, !(digitalRead(heaterPin)));
//}
//
//void recipe1() {
//    // this function calls : open_gate() to move the stepper motor ,
//    // pump() if water is needed(it's called at the begining),
//    // open_close_heater() that takes the required time of heating
//    // the delay time of the DC motor that presses the button of the gate. this time depends on the quantity
//    // delayed time = map(the quantity,min quantity,max quantity,min time,max time);
//}
//
//void recipe2() {}
//
//void recipe3() {}
//
//void recipe4() {}
//
//void recipe5() {}
