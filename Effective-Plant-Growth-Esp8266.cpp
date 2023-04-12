#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "your_SSID"; // Your Wi-Fi SSID
const char* password = "your_PASSWORD"; // Your Wi-Fi password

ESP8266WebServer server(80);

int sensorPin = A0; // Analog input pin that the sensor is attached to

void setup() {
  pinMode(sensorPin, INPUT);

  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  server.on("/", []() {
    String json = "{\"moisture\":" + String(analogRead(sensorPin)) + "}";
    server.send(200, "application/json", json);
  });

  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();
}