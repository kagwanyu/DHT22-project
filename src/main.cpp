#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4 
#define DHTTYPE DHT22  
const unsigned long SAMPLE_MS = 60000;  

DHT dht(DHTPIN, DHTTYPE);
unsigned long lastSample = 0;

void setup() {
  Serial.begin(115200);
  delay(1500);
  dht.begin();

  Serial.println();
  Serial.println("ESP32 DHT Reader Template Ready");
}

void loop() {
  unsigned long now = millis();
  if (lastSample == 0 || now - lastSample >= SAMPLE_MS) {
    lastSample = now;
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
      Serial.println("WARN: Failed to read from DHT sensor.");
    } else {
      Serial.print("Temperature: ");
      Serial.print(t, 1);
      Serial.println(" °C");
      Serial.print("Humidity: ");
      Serial.print(h, 1);
      Serial.println(" %");
    }
    Serial.println("-----------------------------");
  }
  delay(5);
}
