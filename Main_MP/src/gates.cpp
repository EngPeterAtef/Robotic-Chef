////this code is made to use stepper motor with easy driver
//// connections:
//// Arduino    |   Easydriver
////-------------------------
//// 9          |   STEP
//// 8          |   DIR
//// GND        |   GND (adjucent to STEP and DIR)
////            |   GND (OWR IN) to power supply GND
////            |   M+ (PWR IN) to power supply 12V
////            |   MOTOR A pair to motor coil 1
////            |   MOTOR B pair to motor coil 2
//#include <Arduino.h>
//#define stepPerAngle 1.8
//
//#define direction_pin 8
//#define step_pin 9
//#define dc1_pin 13
//#define dc2_pin 12
//#define stepper_enable_pin 6
//
//void setup() {
//    Serial.begin(9600);
//    pinMode(direction_pin, OUTPUT);
//    pinMode(step_pin, OUTPUT);
//    pinMode(stepper_enable_pin, OUTPUT);
//    pinMode(dc1_pin, OUTPUT);
//    pinMode(dc2_pin, OUTPUT);
//
//}
//
///**
// *
// * @param gate_angle  angle of the gate we're heading to
// * @param dc_delay  responsible for different types of ingredients, some require it small or big amount of time
// */
//void open_gate(unsigned short gate_angle, unsigned short dc_delay = 20000) {
//
//    //!NOTE: steps are just an integer anyway -> why Float
//    //!NOTE: gate_angle can be a zero 3ady -- gate at the starting position
//
//    digitalWrite(stepper_enable_pin, HIGH);
//    Serial.println(gate_angle);
//
//    auto steps = (short) (gate_angle / stepPerAngle);
//    digitalWrite(direction_pin, HIGH);
//    for (int i = 0; i < steps; i++) {
//
//        // To execute a step (or in this case , a micro step), toggle the step_pin HIGH/LOW
//        // you can control the speed by the amount of delay you insert in the toggle
//        digitalWrite(step_pin, HIGH);
//        delay(10);     // use delayMicroseconds instead of "delay" in order to make motor move faster
//
//        // there is processing and mechanical limit on the value of the delay
//        digitalWrite(step_pin, LOW);
//        delay(10);
//
//    }
//
//    //dc motor
//    digitalWrite(dc1_pin, LOW);
//    digitalWrite(dc2_pin, HIGH);
//    delay(dc_delay);
//    digitalWrite(dc1_pin, HIGH);
//    digitalWrite(dc2_pin, LOW);
//
//    delay(dc_delay);
//
//    digitalWrite(dc1_pin, LOW);
//    digitalWrite(dc2_pin, LOW);
//    //TODO: Consider that amount of time
//    delay(2000);
//
//    digitalWrite(direction_pin, LOW); // spin in the opposite direction
//    for (int i = 0; i < steps; i++) {
//        // To execute a step (or in this case , a micro step), toggle the step_pin HIGH/LOW
//        digitalWrite(step_pin, HIGH);
//        delay(10);
//        digitalWrite(step_pin, LOW);
//        delay(10);
//    }
//}
//
//
//void loop() {
//    byte recipe;
//    while (true) {
//        if (Serial.available()) {
//            recipe = Serial.read() - '0';
//            Serial.println(recipe);
//            break;
//        }
//    }
//
//    if (recipe == 1) {
//        open_gate(90);
//        delay(1000);
//
//    }
//    delay(3000);
//
//
//}