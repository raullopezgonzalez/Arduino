#include "DHT.h"
#include <LiquidCrystal.h>


#include "pitches.h"
int melody[] = {
NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;

#define DHTPIN 2
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // put your setup code here, to run once:
   lcd.begin(16, 2);
   Serial.begin(9600);
   Serial.println(F("DHTxx test!"));
   dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
   lcd.setCursor(0, 1);
   lcd.print(millis()/1000);
   delay(2000);
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   float f = dht.readTemperature(true);
   if (isnan(h) || isnan(t) || isnan(f)) {
   Serial.println(F("Failed to read from DHT sensor!"));
   return;
   }
   float hif = dht.computeHeatIndex(f, h);
   float hic = dht.computeHeatIndex(t, h, false);
   Serial.print(F("Humidity: "));
   Serial.print(h);
   Serial.print(F("% Temperature: "));
   Serial.print(t);
   Serial.print(F("°C "));
   Serial.print(f);
   Serial.print(F("°F Heat index: "));
   Serial.print(hic);
   Serial.print(F("°C "));
   Serial.print(hif);
   Serial.println(F("°F"));
   lcd.print(F("Humidity: "));
   lcd.print(h);
   lcd.print(F("% Temperature: "));
   lcd.print(t);
   lcd.print(F("°C "));
   lcd.print(f);
   lcd.print(F("°F Heat index: "));
   lcd.print(hic);
   lcd.print(F("°C "));
   lcd.print(hif);
   lcd.println(F("°F"));

    if (h >= 70.00) {
      
      for (int thisNote = 0; thisNote < 4; thisNote++) {
// pin8 output the voice, every scale is 0.5 sencond
        tone(4, melody[thisNote], duration);
        delay(1000);
        }
      delay(2000);
     }
     
    }
