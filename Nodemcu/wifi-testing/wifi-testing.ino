#include <WiFi.h>

const char* ssid = "Ironman"; // Your Wi-Fi SSID
const char* pass = "engineer"; // Your Wi-Fi Password

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  
  Serial.print("Connecting to Wi-Fi");
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWiFi Connection Failed!");
  }
}

void loop() {}
