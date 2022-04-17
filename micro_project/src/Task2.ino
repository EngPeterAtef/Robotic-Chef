#include <SoftwareSerial.h>
char dataRead;
char arr[10];
String words; 
bool newData=false;
char endofLine='\n';
byte i=0;
SoftwareSerial myserial(10,11); //rx,tx
void setup() {
  // put your setup code here, to run once:
       Serial.begin(9600);
       myserial.begin(9600);
       
}

void loop() {
  // put your main code here, to run repeatedly:
         while(myserial.available()>0 && !newData){
          dataRead=myserial.read();
          if(dataRead!=endofLine){
            arr[i]=dataRead;
            i++;
          }
          else{
            arr[i]=endofLine;
            i=0;
            newData=true;
          }
         }
         printdata();
}

void printdata(){
  if(newData == true){
    Serial.print(arr);
    newData=false;
  }
}
