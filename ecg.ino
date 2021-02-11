#define joystick_x  A0 // Joystick pin of x movement ( Up and Down )
#include "pitches.h"  // Monitor

//Because of the range in y axis, I compute the equivalentes  ...    1500uV -- 1.5mV --> 100uV -- 0.1mV


int melody[] = {NOTE_C5,};    // Constant heart sound (sound)
int i;
int reset;
volatile int counter = 0;
const int pinbuzzer = 8; // Buzzer pin 
const int pinbutton = 2; // Button pin
const int red = 9; // led
const int yellow =  11; // led
const int green = 13; // led


void Changer(){                        //Interruption
  counter = counter +1;
  }

void No_alarm(){
  digitalWrite(green,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
  if (reset > 300 || reset < 300){
    digitalWrite(green,LOW);                                        
    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    }
  }
void Alert(){
  if (reset == 300 || reset > 300 || reset < 300){
    digitalWrite(green,LOW);                                         // Leds
    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    }
  }
void Arrhythmia(){
  if (reset == 300 || reset > 300 || reset < 300){
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    }
  }

  
void Heart_sound(){
  for (int thisNote = 0; thisNote < 8; thisNote++){
      tone(pinbuzzer, melody[0], 100);
      }
  }
void No_signal_Sound(){
  for (int thisNote = 0; thisNote < 8; thisNote++){
      tone(pinbuzzer, melody[0], 2000);                       // 2 Minutes with chance of surviving, if not, death 
      }  
  }


void HR(){
  int value_j = analogRead(joystick_x); 

  if(  (value_j >= 200) && (value_j <= 800) ) {                       //Normal Rate = Total number of R's = 72~78 in one minute = normal heart rate
    reset = 300;                          
    }  
  if(  (value_j >= 0) && (value_j < 200) ) {                  
  reset = reset + 50;
  
  if (reset >= 550){                                          // Bradychardia < 60  / min     54 in one minute
    reset = 550;
  }
  }
  if(  (value_j > 800) && (value_j <= 1023) ) {
  reset = reset - 50;
  if (reset <= 100){                                           // Tachycardia > 100 / min    120 in one minute
    reset = 50;
  }
  } 
}

void Constant_ST(){
  for (i = 0; i <= 10; i=i+4){    
  Serial.println(0);
  }                                                     // dura 0.04*4 s de S a T               timing for summing i++ = i+1 = 0.02 seconds or 2ms so computing...                                                       
}
void Constant_PQ(){
  for (i = 0; i <= 10; i=i+2){    
  Serial.println(0);
  }                                                     // dura 0.04*2 s de P a Q                                                         
}
void P_wave(){
  for (i = 0; i < 180; i= i+6){
  float radian = (i * PI) /180;                         // i=degrees  in this case from zero to 180          
  Serial.println(100*sin(radian));                          // 0.05mV A
  }                                                     // dura 0.04*2 s
}
void Q_wave(){
  for (i = 0.0; i >= -100; i = i - 25){
  Serial.println(i);
  }                                                     // dura 0.04*(1/2) s
}
void R_wave(){
  for (float i = -100; i <= 700; i = i +100){
  Serial.println(i);
  if (i==700){
    Heart_sound();
    }
  }
  for (float i = 700; i >= -200; i = i -200){
  Serial.println(i);
  }                                                      // dura 0.04*2 s el total
}
void S_wave(){
  for (float i = -200; i <= 0; i = i +25){
  Serial.println(i);
  }                                                      // dura 0.04*(1/2) s
}
void T_wave(){
  for (i = 0; i < 180; i= i+4){
  float radian = (i * PI) /180;                          // i=degrees
  Serial.println(200*sin(radian));                         //0.05mV A
  }                                                      // dura 0.04*4 s
}
void Constant_Reset(){
  for (i = 0; i <= reset; i++){                          // dura 0.04*8 de T a P (señal nueva)
  Serial.println(0);
  }                                                                                                            
}


void Failure(){  
  Serial.println(0);
  Alert();                                               // Heart failure
  No_signal_Sound();
                                                                
}
void Extra_Systole(){
  Arrhythmia();
  P_wave();
  Constant_PQ();
  Q_wave();                                  
  R_wave();
  S_wave();
  Constant_ST();
  T_wave();
  for (i = 0; i < 180; i= i+6){
    float radian = (i * PI) /180;                         // Extrasystole of 500/-400uV   
    Serial.println(500*sin(radian));                          
    }
  for (i = 0; i < 180; i= i+6){
    float radian = (i * PI) /180;                                  
    Serial.println(-400*sin(radian));                          
    } 
  Constant_Reset(); 
}  
void Normal(){
  No_alarm();
  P_wave();
  Constant_PQ();
  Q_wave();                                  
  R_wave();
  S_wave();
  Constant_ST();
  T_wave();
  Constant_Reset();
  }

void Auricular_flutter(){
  Arrhythmia();
  P_wave();
  Constant_PQ();
  Q_wave();                                  
  R_wave();
  S_wave();
  Constant_ST();
}
void Ventricular_flutter(){
  Arrhythmia();
  T_wave();
  for (i = 0; i < 180; i= i+4){            // Negative T wave
  float radian = (i * PI) /180;                        
  Serial.println(-200*sin(radian));                        
  } 
}



void ECGs(){
  if (counter==0){       // Normal person
    Normal();
    }
  if (counter==1){
    Extra_Systole();                                                   
    }
  if (counter==2){                             
    Auricular_flutter();
    } 
  if (counter==3){                             
    Ventricular_flutter();
    } 
  if (counter==4){                             
    Failure();
    } 
  if (counter==5){                             
    counter = 0; 
    
}
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600*2);
  attachInterrupt(digitalPinToInterrupt(pinbutton), Changer, RISING); 
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  HR();
  ECGs();
}
