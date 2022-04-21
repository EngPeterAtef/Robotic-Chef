// Libraries
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <../.pio/libdeps/uno/Stepper/src/Stepper.h>
#include <../.pio/libdeps/uno/Servo/src/Servo.h>
#include <Wire.h>

//-------------------------------------
// Constants related to the Application
#define NUM_RECIPES 5
#define stepPerAngle 1.8
#define endOfLine 's'

#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5

// Pins
#define heaterPin 0
#define pipePin 1
#define bluetoothPin1 10
#define bluetoothPin2 11
#define direction_pin 8
#define step_pin 9
#define dc1_pin 13
#define dc2_pin 12
#define stepper_enable_pin 6


void recipe1();

void recipe2();

void recipe3();

void recipe4();

void recipe5();

void receive();

void (*recipes_func[NUM_RECIPES])() = {&recipe1, &recipe2, &recipe3, &recipe4,
                                       &recipe5}; // Array of function pointer to each recipe

// Opens a Specific Gate
void open_gate(int gate_number, unsigned short dc_delay = 8000);

void pump(int amountWater);

void inline open_close_heater();

// Variables taken from user
byte quantities[10];                                      // 10 is the max number of variables in all recipes it could be changed
SoftwareSerial mybluetooth(bluetoothPin1, bluetoothPin2); // rx,tx
