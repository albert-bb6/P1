#include <Arduino.h>
#define LED_BUILTIN 2
#define DELAY 1000

void setup() {
 pinMode(LED_BUILTIN, OUTPUT);
 Serial.begin(115200);
}
void loop() {
 digitalWrite(LED_BUILTIN, HIGH);
 Serial.println("ON");
 delay(DELAY);
 digitalWrite(LED_BUILTIN, LOW);
  Serial.println("OFF");
 delay(DELAY);
}