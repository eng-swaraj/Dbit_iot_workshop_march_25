#include <WiFi.h>

const char* ssid = "ironman";      // Your WiFi Name
const char* password = "engineer"; // Your WiFi Password

WiFiServer server(80);  // Web server on port 80
int ledPin = 2;         // Onboard LED

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);

    Serial.println("\nConnecting to WiFi...");
    WiFi.begin(ssid, password);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) { 
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\n✅ Connected to WiFi!");
        Serial.print("ESP32 IP Address: ");
        Serial.println(WiFi.localIP());
        server.begin();  // Start web server
    } else {
        Serial.println("\n❌ Failed to connect. Check SSID/Password.");
    }
}

void loop() {
    WiFiClient client = server.available();
    if (!client) return;

    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/LEDON") != -1) {
        digitalWrite(ledPin, HIGH);
    } 
    if (request.indexOf("/LEDOFF") != -1) {
        digitalWrite(ledPin, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<h1>ESP32 LED Control</h1>");
    client.println("<a href='/LEDON'><button>ON</button></a>");
    client.println("<a href='/LEDOFF'><button>OFF</button></a>");
    client.println();
    client.stop();
}
//http://10.181.169.17/LEDON

-------------------------------
    #include <ESP8266WiFi.h>

const char* ssid = "ironman";      // Your WiFi Name
const char* password = "engineer"; // Your WiFi Password

WiFiServer server(80);  // Web server on port 80
int ledPin = 2;         // Onboard LED (D4 on NodeMCU)

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    Serial.println("\nConnecting to WiFi...");
    WiFi.begin(ssid, password);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) { 
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\n✅ Connected to WiFi!");
        Serial.print("NodeMCU IP Address: ");
        Serial.println(WiFi.localIP());
        server.begin();  // Start web server
    } else {
        Serial.println("\n❌ Failed to connect. Check SSID/Password.");
    }
}

void loop() {
    WiFiClient client = server.available();
    if (!client) return;

    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/LEDON") != -1) {
        digitalWrite(ledPin, HIGH);
    } 
    if (request.indexOf("/LEDOFF") != -1) {
        digitalWrite(ledPin, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<h1>NodeMCU LED Control</h1>");
    client.println("<a href='/LEDON'><button>ON</button></a>");
    client.println("<a href='/LEDOFF'><button>OFF</button></a>");
    client.println();
    client.stop();
}
// Access via: http://<NodeMCU-IP>/LEDON or /LEDOFF
