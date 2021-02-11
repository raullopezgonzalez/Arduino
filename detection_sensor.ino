#include <afstandssensor.h>

                                        // AfstandsSensor(triggerPin, echoPin);
AfstandsSensor afstandssensor(A0,A1); // Starter afstandssensoren på ben 2 og 12.

void setup () {
    Serial.begin(9600);  // Opsætter serial kommunikation tilbage til computeren
}

void loop () {
    // Måler afstanden for hver 500ms
    Serial.println(afstandssensor.afstandCM());
    delay(500);
}
