// #include <SoftwareSerial.h>
// #include <Arduino.h>

// char dataRead;
// byte quantities[10];

// // 1 2 3 's' 
// #define endofLine '\n'

// SoftwareSerial mybluetooth(10, 11); // rx,tx
// void setup()
// {
//     // put your setup code here, to run once:
//     Serial.begin(9600);
//     mybluetooth.begin(9600);
// }
// // 1 0 5 6 4 's'

// void loop()
// {
//     bool finishedReading = false;
//     byte i = 0;

//     while (!finishedReading)
//     {
//         while (mybluetooth.available() > 0)
//         {
//             char dataRead = mybluetooth.read();

//             if (dataRead != endofLine)
//             {
//                 quantities[i] = dataRead;
//                 i++;
//             }
//             else
//             {
//                 finishedReading = true;
//                 break; // wont break till all message has been read
//             }
//         }
//     }
//     processData();
// }

// void processData()
// {
//     Serial.println(quantities);
// }
