#include "pitches.h" // I include the librery for the melody


int melody[] = {
NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5}; // Here are the four samples that is going to sound by the buzzer


int duration = 500; // Duration in time (ms) of each note  ; 

volatile int variable = 5000; // Whenever its value can be changed by something beyond the control (Us pessing button) of the code section in which it appears
const int maxima = 10000;
const int minima = 1000;
const int cambio = 1000;


void setup() {
  // put your setup code here, to run once:

  attachInterrupt(digitalPinToInterrupt(2), Up, RISING); // The previous step to declare the pin of interrupting, ist name as function and the state where will be active the function
  attachInterrupt(digitalPinToInterrupt(3), Down, RISING); // Our arduino only has 2, 3. Putting 0 == 2 and 1 == 3 in case of only Pin instea of digital..

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int thisNote = 0; thisNote < 4; thisNote++) {  // Loop from 0 (+1 each time) to 4
// pin8 output the voice, every scale is 0.5 sencond
    tone(8, melody[thisNote], duration);
    delay(1000); // Time between notes
}
delay(variable); // Time between loop-action

}

void Up()  
{
  variable = variable + cambio;
  if (variable > maxima)
  {
     variable == maxima; }
}

void Down()   
{
  variable = variable - cambio;
  if (variable < minima)
  {
     variable == minima; }
}
 
