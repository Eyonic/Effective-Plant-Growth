#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Wire.h>
#include <Adafruit_SleepyDog.h>

const char* ssid = "your_SSID"; // Your Wi-Fi SSID
const char* password = "your_PASSWORD"; // Your Wi-Fi password

ESP8266WebServer server(80);

const int sensorPin = A0; // Analog input pin that the sensor is attached to

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  MDNS.begin("esp8266");

  server.on("/", []() {
    String json = "{\"moisture\":" + String(analogRead(sensorPin)) + "}";
    server.send(200, "application/json", json);
  });

  server.begin();

  Serial.println("Server started");

  ESP.deepSleep(24 * 60 * 60e6); // sleep for 24 hours
}

void loop() {
  // This code won't be executed since the ESP is in deep sleep mode
  // and will only wake up after the specified time.
}