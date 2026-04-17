#include <WiFi.h>
#include <HTTPClient.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak
String apiKey = "YOUR_WRITE_API_KEY";
const char* server = "http://api.thingspeak.com/update";

// Pins
#define MOISTURE_PIN 34
#define RELAY_PIN 5
#define LED_PIN 2

// Threshold
int MOISTURE_THRESHOLD = 2000;

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Power ON initially

  // Connect WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi!");
}

void loop() {

  int moisture = analogRead(MOISTURE_PIN);

  Serial.print("Moisture: ");
  Serial.println(moisture);

  bool wetCondition = (moisture < MOISTURE_THRESHOLD);

  if (wetCondition) {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("⚠ WET CONDITION - POWER OFF");
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_PIN, LOW);
    Serial.println("SAFE CONDITION");
  }

  // -------- SEND TO THINGSPEAK --------
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url = server;
    url += "?api_key=" + apiKey;
    url += "&field1=" + String(moisture);

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.println("Data sent to ThingSpeak!");
    } else {
      Serial.println("Error sending data");
    }

    http.end();
  }

  delay(15000); // ThingSpeak limit (15 sec)
}