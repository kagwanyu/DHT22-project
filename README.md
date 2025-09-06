 ESP32, DH22 Temperature and humidity sensor project
 Firmware project for ESP32-WROOM that reads temperature and humidity from a DHT22 sensor and prints values to the Serial Monitor.
This project includes simulation support in Wokwi, making it runnable even without physical hardware.
Features:  Reads temperature (°C) and humidity (%) every 60 seconds.
           Implements defensive programming: retries on failed sensor reads before reporting errors.
           Runs on ESP32 with Arduino framework (PlatformIO).
           Works both on real hardware and Wokwi simulator.
           Clean output formatting for easy presentation/logging.
Hardware Setup :
                3v esp32 pin to dht22 vcc
                ground esp32 to dht22 ground
                GPIO 4 esp32 to data pin on dht22 which is the SDA pin
Design Decisions :
                 Defensive Programming: checks for NaN values to avoid false readings.
                 Retry Mechanism: up to 3 attempts before reporting an error.
                 Non-blocking timing (millis()): keeps system responsive.
                 Safe GPIO pin choice (4 by default, 15 in Wokwi): avoids ESP32 boot issues.           
Wokwi simulation - https://wokwi.com/projects/441259201266404353                
                
      
