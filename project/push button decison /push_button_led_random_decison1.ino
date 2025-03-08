int buttonPin = 2;
int ledPin = 13;
bool buttonState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  randomSeed(analogRead(0)); // Seed random number generator
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    int result = random(2); // Randomly choose 0 ('No') or 1 ('Yes')

    if (result == 1) {
      // 'Yes' - Fast blinks
      for (int i = 0; i < 3; i++) {
        digitalWrite(ledPin, HIGH);
        delay(200);
        digitalWrite(ledPin, LOW);
        delay(200);
      }
    } else {
      // 'No' - Slow blinks
      for (int i = 0; i < 2; i++) {
        digitalWrite(ledPin, HIGH);
        delay(600);
        digitalWrite(ledPin, LOW);
        delay(600);
      }
    }

    delay(1000); // Prevent multiple triggers due to button bounce
  }
}
