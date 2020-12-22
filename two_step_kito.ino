#include "SevenSegmentTM1637.h"
const byte PIN_CLK = 8; // define CLK pin (any digital pin)
const byte PIN_DIO = 5; // define DIO pin (any digital pin)
SevenSegmentTM1637 display(PIN_CLK, PIN_DIO);
const int stepPin = 3; 
const int dirPin = 4; 
const int stepPin1 = 6; 
const int dirPin1 = 7; 
int servoPin1 = 9;   
int data=10;
int count=0;
void setup(){
  Serial.begin(9600);
  display.begin();        
  display.setBacklight(100);
  display.clear();
  display.print(count);
  pinMode(servoPin1, OUTPUT);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
 
  servo1(0);

}


void servo1(int angle1) { 
  
  for(int i=0;i<50;i++){
    int val = (angle1 * 11) + 500; 
    digitalWrite(servoPin1, HIGH); 
    delayMicroseconds(val);  
    digitalWrite(servoPin1, LOW);  
    delayMicroseconds(20000 - val);
  }
  delay(100);
}
 
void loop() {
  

  while(data>0){
     Serial.print(data);
  
    delay(1000);
     data--;
  
   if(data==0){

     
  digitalWrite(dirPin1,LOW); 
  
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(5000);
  
 digitalWrite(dirPin,HIGH); 
  
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000);
  servo1(60);
  servo1(0);
  servo1(60);
  servo1(0);
  servo1(60);
  servo1(0);
  
  delay(1000);
  
   digitalWrite(dirPin1,HIGH); 
  
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  delay(2000);
  
  digitalWrite(dirPin,HIGH);
 
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  display.clear();
  count=count+1;;
  display.print(count);
  data=10;
   }
  }
  
}
 
