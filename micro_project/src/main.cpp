// Libraries
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Stepper.h>
#include <Servo.h>

// Variables taken from user
int recipeID;       // ID taken from the user represnts the required recipe
int quantities[10]; // 10 is the max number of variables in all recipes it could be changed
int heatTime;       // variable for heating time is set by the user
//-------------------------------------
// Data related to the Application
#define R1 1;
#define R2 2;
#define R3 3;
#define R4 4;
#define R5 5;
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
  
  
  
  // if (recipe == 1)
  // {
  //   // for loop over the number of variables of this recipe
  // } // and so on
}
//------------------
void rotate(int angle)
{
  // takes the target angle
  //  if(current_angle > angle){
  //  while(angle != current angle){
  //    current angle -=step angle bettween each container;
  //  }
  //  }
}
//------------------------
// function pump that takes the quantity of required water
void pump(int amountWater)
{
  // control the relay to be high during droping time depends on the amount of water sent
}
//-----------------------------
// function takes the required time of heating and controls the heater
void heat(int Htime)
{
}
//------------------------
void recipe1()
{
  // this function calls : rotate() to move the stepper motor ,
  // pump() if water is needed(it's called at the begining),
  // heat() that takes the required time of heating
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
  receive(); // get data
  if (recipeID == 1)
  {
    recipe1();
  }
  else if (recipeID == 2)
  {

  } // and so on
}
