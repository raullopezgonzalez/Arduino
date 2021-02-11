float vtg;
float n = 102.3;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  vtg = analogRead(A0);

  if (vtg<=n){
    digitalWrite(2,HIGH);
    
    }
    else digitalWrite(2,LOW);
  if (vtg<=2*n){
    digitalWrite(3,HIGH);
    
    }
     else digitalWrite(3,LOW);
  if (vtg<=3*n){
    digitalWrite(4,HIGH);
    
    }
     else digitalWrite(4,LOW);
  if (vtg<=4*n){
    digitalWrite(5,HIGH);
    
    }
     else digitalWrite(5,LOW);

   if (vtg<=5*n){
    digitalWrite(6,HIGH);
    
    }
     else digitalWrite(6,LOW);

   if (vtg<=6*n){
    digitalWrite(7,HIGH);
    
    }
     else digitalWrite(7,LOW);
    if (vtg<=7*n){
    digitalWrite(8,HIGH);
    
    }
     else digitalWrite(8,LOW);
    if (vtg<=8*n){
    digitalWrite(9,HIGH);
    
    }
     else digitalWrite(9,LOW);
    if (vtg<=9*n){
    digitalWrite(10,HIGH);
    
    }
     else digitalWrite(10,LOW);
    if (vtg<=10*n){
    digitalWrite(11,HIGH);
    
    }
     else digitalWrite(11,LOW);
}
