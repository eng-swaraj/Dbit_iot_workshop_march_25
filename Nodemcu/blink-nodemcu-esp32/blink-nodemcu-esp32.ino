#define LED_PIN 2  // ESP32 onboard LED is usually on GPIO 2

void setup() {
  pinMode(LED_PIN, OUTPUT); // Set LED pin as output
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn LED ON
  delay(1000); // Wait 1 second
  digitalWrite(LED_PIN, LOW);  // Turn LED OFF
  delay(1000); // Wait 1 second
}
