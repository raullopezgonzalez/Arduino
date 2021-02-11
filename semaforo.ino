#include <Servo.h>
Servo myservo;  // sirve esto??? ya que luego lo utilizo con otro nombre
int servoPin = 4; // pin 4
Servo Servo1;
#include <afstandssensor.h>
AfstandsSensor afstandssensor(A0, A1);
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);            
const int buttonPin = 5;
bool buttonState = 0;                                                    // trig -> 2,  eko -> 1
float p_free = 15; // plazas libres

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  Servo1.attach(servoPin); 
  pinMode(3,OUTPUT); // rojo
  pinMode(6,OUTPUT); // verde    ...      con sus respectivos pins
  pinMode(13,OUTPUT); // amarillo
  pinMode(buttonPin, INPUT);
  Serial.print("Places: 15 ");
  lcd.print("Places: 15 ");

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);
  buttonState = digitalRead(buttonPin);

  float d = afstandssensor.afstandCM();
  Serial.println(d);
  delay(500);
  if (d <= 5.00) {
    p_free = p_free - 1;
    Servo1.write(90); 
    delay(6000);
    Servo1.write(-90); 
    Serial.print("Places free: ");
    lcd.print("Places free: ");
    Serial.print(p_free);
    lcd.print(p_free);
    if (p_free == 0) {
      Serial.print("Not space");
      lcd.print("Not space");
      }
    else {   // faltaría aplicar en este loop el hecho de que te siga imprimiendo los aparcamientos sin cambios en la variable ya que no ha entrado nadie
      Serial.print("Chance to park");
      lcd.print("Chance to park");
      } 
    }

  if (buttonState == HIGH) {
    digitalWrite(3, LOW);
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(6,HIGH);
    delay(2000);
    digitalWrite(6,LOW);
    digitalWrite(3,HIGH);

    } 
  else {
    digitalWrite(3,HIGH);
  }
     
  
  
}
