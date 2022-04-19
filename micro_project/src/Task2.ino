#include <SoftwareSerial.h>
#include <Arduino.h>

char dataRead;
char quantities[10];

#define endofLine 's'
SoftwareSerial mybluetooth(10, 11); // rx,tx
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    mybluetooth.begin(9600);
}

void loop()
{
    bool finishedReading = false;
    byte i = 0;

    while (!finishedReading)
    {
        while (mybluetooth.available() > 0)
        {
            char dataRead = mybluetooth.read();

            if (dataRead != endofLine)
            {
                quantities[i] = dataRead;
                i++;
            }
            else
            {
                finishedReading = true;
                break; // wont break till all message has been read
            }
        }
    }
    processData();
}

void processData()
{
    Serial.println(quantities);
}
