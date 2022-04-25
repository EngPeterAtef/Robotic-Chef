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
#define pumpPin 1
#define bluetoothPin1 10
#define bluetoothPin2 11
#define direction_pin 8
#define step_pin 9
#define dc1_pin 13
#define dc2_pin 12
#define stepper_enable_pin 6

// Gates ANGLE IN Degrees
#define TEA_GATE 0
#define SUGAR_GATE 25
#define PASTA_GATE 50
#define SALT_GATE 75
#define PEPPER_GATE 100
//....

void recipe1();

void recipe2();

void recipe3();

void recipe4();

void recipe5();

void receive();

void (*recipes_func[NUM_RECIPES])() = {&recipe1, &recipe2, &recipe3, &recipe4,
                                       &recipe5}; // Array of function pointer to each recipe

// Opens a Specific Gate
void open_gate(unsigned short gate_angle, unsigned short dc_delay);

void pump(int amountWater);


// Variables taken from user
byte quantities[10];                                      // 10 is the max number of variables in all recipes it could be changed

//blue is connected otherwise
SoftwareSerial mybluetooth(bluetoothPin1, bluetoothPin2); // rx,tx
