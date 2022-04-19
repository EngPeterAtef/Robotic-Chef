// #include <SoftwareSerial.h>
// #include <Arduino.h>

// char dataRead;
// char quantities[10];

// #define endofLine 's'
// SoftwareSerial myserial(10, 11); // rx,tx
// void setup()
// {
//     // put your setup code here, to run once:
//     Serial.begin(9600);
//     myserial.begin(9600);
// }

// void loop()
// {
//     // put your main code here, to run repeatedly:
//     bool finishedReading = false;
//     byte i = 0;

//     while (myserial.available() > 0 && !finishedReading)
//     {
//         dataRead = myserial.read();

//         if (dataRead != endofLine)
//         {
//             quantities[i] = dataRead;
//             i++;
//         }
//         else
//         {
//             quantities[i] = endofLine;
//             i = 0;
//             finishedReading = true;
//         }
//     }
//     processData();
//     finishedReading = false;
// }

// void processData()
// {
//     Serial.print(quantities);
// }
