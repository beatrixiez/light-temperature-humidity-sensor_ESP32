#include <DHT.h>
#include <ArduinoJson.h>

#define DHT22_PIN  21
#define LDR_PIN 32

DHT dht22(DHT22_PIN, DHT22);

void setup() {
  Serial.begin(9600);
  dht22.begin();
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  float temperature = dht22.readTemperature();
  float humidity = dht22.readHumidity();
  int luminosity = analogRead(LDR_PIN);

  StaticJsonDocument<200> jsonDoc;
  jsonDoc["temperatura"] = temperature;
  jsonDoc["umidade"] = humidity;
  jsonDoc["luminosidade"] = luminosity;

  String jsonString;
  serializeJson(jsonDoc, jsonString);
  Serial.println(jsonString);

  delay(4000);
}
