#include "DHT.h"
#include <LiquidCrystal.h>

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
 // Reading temperature or humidity takes about 250 milliseconds!
 // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
     float h = dht.readHumidity();
     // Read temperature as Celsius (the default)
     float t = dht.readTemperature();
     // Read temperature as Fahrenheit (isFahrenheit = true)
     float f = dht.readTemperature(true);
     // Check if any reads failed and exit early (to try again).
     if (isnan(h) || isnan(t) || isnan(f)) { // The || means or
     Serial.println(F("Failed to read from DHT sensor!"));
     return;
     }
     // Compute heat index in Fahrenheit (the default)
     float hif = dht.computeHeatIndex(f, h);
     // Compute heat index in Celsius (isFahreheit = false)
     float hic = dht.computeHeatIndex(t, h, false);
     Serial.print(F("Humidity: "));     //If you use F() you can move constant strings to the program memory instead of the ram ¡¡¡¡¡¡
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
    }
