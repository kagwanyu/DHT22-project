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

    float h, t;
    int attempts = 0;
    const int maxAttempts = 3;
    const int retryDelay = 2000;

    while (attempts < maxAttempts) {
      h = dht.readHumidity();
      t = dht.readTemperature();

      if ( !isnan(h) && !isnan(t)){
        Serial.print("Temprature:");
        Serial.print(t, 1);
        Serial.print(" °C");

        Serial.print("Humidity: ");
        Serial.print(h, 1);
        Serial.print("%");
        break;
      }
      else {
        Serial.print("WARN: Failed to read from DHT sensor. Attemt");
          Serial.println(attempts + 1);
          delay(retryDelay);
          attempts++;
      }

      
    }

    if (attempts == maxAttempts){
      Serial.println("ERROR: Max attempts reached.Sample skipped.");
    }
    Serial.println("-----------------------------");
  }
  delay(5);
}
