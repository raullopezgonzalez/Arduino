#include <Stepper.h> // Include the Arduino Stepper.h library
#define joystick_x  A0 // Joystick pin of x movement ( Up and Down )

#define IN1  8
#define IN2  9
#define IN3  10      // Pins for the servo module
#define IN4  11

const int stepsPerRevolution = 400;  // change this to fit the number of steps per revolution for your motor

int spd = 30; // variable for the velocity
int acc = 0; // acc parameter
int decc = 0; // deccc parameter

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);   // initialize the stepper library on pins 8 through 11:

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int val = analogRead(joystick_x);
  
  if(  (val > 100) && (val < 900) ) {
    Stop();
    Checking();
    }
  
  if (val >= 900){  // move the motor in the first direction
    Right_with_acc();
    Checking();
    }
     
  if (val <= 100){  // move the motor in the other direction
    Left_with_decc();
    Checking();
    }
 
 }
                          
// Functions ¡!¡!¡!¡!¡!¡!

void Checking(){
  analogRead(joystick_x);
 }

void Stop(){   // Stop movcement
  digitalWrite(IN1, LOW);     // No currento towards motor in any connection 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  spd = 30;   // Reset of standard velocity and no quantity in both acceleration parameters
  acc = 0;
  decc = 0;
 }

void Right_with_acc(){  // Clockwise 
  acc = acc + 10;
  if (acc>= 120){
    acc = 120;  // Speed limit
  }
  spd = acc;
  myStepper.setSpeed(spd);
  myStepper.step(stepsPerRevolution);
}

void Left_with_decc(){  // Counterclockwise 
  decc = decc + 10;
  if (decc >= 120){
    decc = 120;   // Speed limit
  }
  spd = decc;
  myStepper.setSpeed(spd);
  myStepper.step(-stepsPerRevolution);
}
