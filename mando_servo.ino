#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN); 
decode_results results;  

void translateIR() {
switch (results.value) 
        {
        case 0xFF30CF:               // founded after uploading a code to arduino where it plots each command on monitor serie for each button
          Serial.println("1");
          break;
        case 0xFF6897:               // same
          Serial.println("0");
          break; 
default:
        Serial.print("You have pressed a functionless button");    // This part of the code updated after the video where i show fixxing error of the controler   
        }
}
        

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();  
  
}

void loop(){
  if (irrecv.decode(&results)){
        translateIR(); 
        delay(500);
        irrecv.resume();
  }
}
