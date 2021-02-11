float pot;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600); //Establece la velocidad de datos en bits por segundo (baudios) para la transmisión de datos en serie

} 

void loop() {
  // put your main code here, to run repeatedly:
  pot = analogRead(A0);
  pot = pot*5/1023;
  Serial.println(pot);
  
  

}
