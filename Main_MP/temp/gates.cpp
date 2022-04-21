//this code is made to use stepper motor with easy driver
// connections:
// Arduino    |   Easydriver
//-------------------------
// 9          |   STEP
// 8          |   DIR
// GND        |   GND (adjucent to STEP and DIR)
//            |   GND (OWR IN) to power supply GND
//            |   M+ (PWR IN) to power supply 12V
//            |   MOTOR A pair to motor coil 1
//            |   MOTOR B pair to motor coil 2
#include <Arduino.h>
int direction_pin = 8;
int step_pin      = 9;
const float stepPerAngle = 1.8;

int angle;
int receipe;
void setup()
{
    Serial.begin(9600);
    pinMode(direction_pin, OUTPUT);
    pinMode(step_pin, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(13,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(11,OUTPUT);
    //digitalWrite(6,HIGH);
    //digitalWrite(direction_pin, HIGH);
}
void rotate(int angle)
{
    if (angle != 0)
    {
        digitalWrite(6,HIGH);
        Serial.println(angle);
        float steps = angle / stepPerAngle;
        digitalWrite(direction_pin, HIGH);
        for (int i = 0; i < steps; i++)
        {
            Serial.println(angle);
            // To execute a step (or in this case , a microstep), toggle the step_pin HIGH/LOW
            // you can control the speed by the amount of delay you insert in the toggle
            digitalWrite(step_pin, HIGH);
            delay(10);     // use delayMicroseconds instead of "delay" in order to make motor move faster

            // there is processing and mechanical limit on the value of the delay
            digitalWrite(step_pin, LOW);
            delay(10);
        }
        //dcmotor
        //analogWrite(11,100) ;
        digitalWrite(13,LOW) ;
        digitalWrite(12,HIGH) ;
        delay(8000);
        digitalWrite(13,HIGH) ;
        digitalWrite(12,LOW) ;
        delay(8000);
        digitalWrite(13,LOW) ;
        digitalWrite(12,LOW) ;
        delay(2000);

        digitalWrite(direction_pin, LOW); // spin in the opposite direction

        // Move the shaft 1600 microsteps towards the opposite direction.
        for (int i = 0; i < steps; i++)
        {
            // To execute a step (or in this case , a microstep), toggle the step_pin HIGH/LOW
            digitalWrite(step_pin, HIGH);
            delay(10);
            digitalWrite(step_pin, LOW);
            delay(10);
        }
    }

}

void loop()
{
    again:
    if (Serial.available()) {
        // angle = Serial.parseInt();
        receipe = Serial.parseInt();
        Serial.println(receipe);
    }
    else {
        goto again;
    }
    if(receipe==1)
    {
        rotate(90);
        delay(1000);
        rotate(90);
        delay(1000);
    }
    delay(3000);


}