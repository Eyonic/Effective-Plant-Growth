#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "your_SSID"; // Your Wi-Fi SSID
const char* password = "your_PASSWORD"; // Your Wi-Fi password

ESP8266WebServer server(80);

int moisturePin = A0; // Analog input pin that the moisture sensor is attached to
int lightPin = A1; // Analog input pin that the light sensor is attached to

// Define the sleep time in seconds (86400 seconds = 24 hours)
const int sleepTime = 86400;

void setup() {
  pinMode(moisturePin, INPUT);
  pinMode(lightPin, INPUT);

  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  server.on("/", []() {
    int moistureValue = analogRead(moisturePin);
    int lightValue = analogRead(lightPin);
    String json = "{\"moisture\":" + String(moistureValue) + ",\"light\":" + String(lightValue) + "}";
    server.send(200, "application/json", json);
    Serial.print("Moisture value: ");
    Serial.println(moistureValue);
    Serial.print("Light value: ");
    Serial.println(lightValue);
  });

  server.begin();
  Serial.println("Server started");

  // Enter deep sleep mode for the specified sleep time
  Serial.print("Entering deep sleep for ");
  Serial.print(sleepTime);
  Serial.println(" seconds");
  ESP.deepSleep(sleepTime * 1000000);
}

void loop() {
  // This code will not be executed as the ESP8266 is in deep sleep mode
}