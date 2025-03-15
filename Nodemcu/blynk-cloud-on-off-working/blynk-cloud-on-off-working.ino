#define BLYNK_TEMPLATE_ID "TMPL3RvnrBgxp"
#define BLYNK_TEMPLATE_NAME "wifi"
#define BLYNK_AUTH_TOKEN "8ARYB5qJwWO1QgwanU4g6vM51Gr-oSmC"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;

char ssid[] = "ironman";
char pass[] = "engineer";

#define LED_PIN 2

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");

    Blynk.config(BLYNK_AUTH_TOKEN);
    Blynk.connect();

    Serial.println("Blynk Connected!");

    timer.setInterval(1000L, []() {
        Serial.println("ESP32 Running...");
    });
}

// Blynk LED Control
BLYNK_WRITE(V0) {
    int ledState = param.asInt();
    digitalWrite(LED_PIN, ledState);
    Serial.print("LED State: ");
    Serial.println(ledState);
}

void loop() {
    Blynk.run();
    timer.run();
}
