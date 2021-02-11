#include <Servo.h>

int servoPin = 4; // pin 4
Servo Servo1;

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(servoPin);
  pinMode(4, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 char c;
 if(Serial.available()>0){
  c = Serial.read();
 if (c == '1'){
   Servo1.write(180); 
  }
 if (c == '0'){
    Servo1.write(-180);
  }
 }
}
