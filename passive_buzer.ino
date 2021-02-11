#include "pitches.h"
int melody[] = {
NOTE_C5,};
int duration = 100;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int thisNote = 0; thisNote < 8; thisNote++) { // the ++ means +1 on this var
// pin8 output the voice, every scale is 0.5 sencond
    tone(8, melody[thisNote], duration);
    delay(5000);
}
delay(2000);

}
