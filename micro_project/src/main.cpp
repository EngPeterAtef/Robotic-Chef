// // Libraries
// #include <Arduino.h>
// #include <SoftwareSerial.h>
// #include <Stepper.h>
// #include <Servo.h>
// #include <Wire.h>

// //-------------------------------------
// // Constants related to the Application
// #define R1 1
// #define R2 2
// #define R3 3
// #define R4 4
// #define R5 5
// #define NUM_RECIPES 5
// // Pins
// #define heaterPin 0
// #define pipePin 1
// #define bluetoothPin 2
// #define bluetoothPin2 2

// void recipe1();
// void recipe2();
// void recipe3();
// void recipe4();
// void recipe5();

// void (*recipes_func[NUM_RECIPES])() = {&recipe1, &recipe2, &recipe3, &recipe4, &recipe5}; // Array of function pointer to each recipe

// // Variables taken from user
// char quantities[10]; // 10 is the max number of variables in all recipes it could be changed
// //----------------------
// // Gates Variables

// //-------------------------
// // Opening Gate Arm Variables
// //-------------------------

// // Function to receive the recipeID from the user and depends on this id it will take number of specific variables
// void receive(byte &recipeID)
// {
//   // 1-read ID
//   // 2-fill quantities
// }
// //------------------

// // Opens a Specific Gate
// void open_gate(int gate_number);

// //------------------------
// // function pump that takes the quantity of required water
// void pump(int amountWater)
// {
//   // control the relay to be high during droping time depends on the amount of water sent
//   digitalWrite(pipePin, HIGH);
//   delay(amountWater * 100);
//   digitalWrite(pipePin, LOW);
// }
// //-----------------------------
// // opens heater if closed or close it if open
// void inline open_close_heater()
// {
//   digitalWrite(heaterPin, !(digitalRead(heaterPin)));
// }
// //------------------------

// void recipe1()
// {
//   // this function calls : open_gate() to move the stepper motor ,
//   // pump() if water is needed(it's called at the begining),
//   // open_close_heater() that takes the required time of heating
//   // the delay time of the DC motor that presses the button of the gate. this time depends on the quantity
//   // delayed time = map(the quantity,min quantity,max quantity,min time,max time);
// }


// void setup()
// {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   Wire.begin(); // join i2c bus as a Master // i2c pins are connected to D15 and D16
// }
// void loop()
// {

//   // Blocking Receive
//   // recipeID is send by referece
//   // bytes are unsigned data type
//   byte recipeID = -1;
//   receive(recipeID);

//   Wire.beginTransmission(7); // transmit to device #7
//   Wire.write(recipeID);      // sends one byte to the other arduino
//   Wire.endTransmission();    // stop transmitting

//   /**
//    *
//    *  it will send the ID to the other arduino so that it starts its job too
//    * NOTE: we can use a pipe to sync the actions between the 2 arduinos
//    *
//    */

//   recipes_func[recipeID - 1](); // Call The corresponding recipe function (assumed ID startes with 1)
// }
