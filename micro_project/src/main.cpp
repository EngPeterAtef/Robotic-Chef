// Libraries
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Stepper.h>
#include <Servo.h>
//-------------------------------------
// Constants related to the Application
#define R1 1;
#define R2 2;
#define R3 3;
#define R4 4;
#define R5 5;
#define NUM_RECIPES 5
// Pins
#define heaterPin 0;
#define pipePin 1;
#define bluetoothPin 2;
#define bluetoothPin2 2;

void recipe1();
void recipe2();
void recipe3();
void recipe4();
void recipe5();

void (*recipes_func[NUM_RECIPES])() = {&recipe1, &recipe2, &recipe3, &recipe4, &recipe5}; // Array of function pointer to each recipe

// Variables taken from user
int recipeID;       // ID taken from the user represnts the required recipe
int quantities[10]; // 10 is the max number of variables in all recipes it could be changed
int heatTime;       // variable for heating time is set by the user

//----------------------
// Gates Variables

//-------------------------
// Opening Gate Arm Variables

//-------------------------

// Function to receive the recipeID from the user and depends on this id it will take number of specific variables
void receive()
{
  // 1-read ID
  // 2-fill quantities
}
//------------------

// Opens a Specific Gate
void open_gate(int gate_number);

//------------------------
// function pump that takes the quantity of required water
void pump(int amountWater)
{
  // control the relay to be high during droping time depends on the amount of water sent
}
//-----------------------------
// function opens heater if closed or close it if open
void open_close_heater()
{
}
//------------------------

void recipe1()
{
  // this function calls : open_gate() to move the stepper motor ,
  // pump() if water is needed(it's called at the begining),
  // open_close_heater() that takes the required time of heating
  // the delay time of the DC motor that presses the button of the gate. this time depends on the quantity
  // delayed time = map(the quantity,min quantity,max quantity,min time,max time);
}
//-------------

// There is a function for each recipe
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop()
{
  // put your main code here, to run repeatedly:

  // Blocking Receive
  receive(); // get data

  recipes_func[recipeID - 1](); // Call The corresponding recipe function
}
