#include "DHT.h"
#define DHTPIN D2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
long lastMillis = 0;
void setup(){
    Serial.begin(115200);
    dht.begin();
    delay(10);
}
void loop(){


      float humedad = dht.readHumidity();
      float temperatura = dht.readTemperature();
      
            lastMillis = millis();
            Serial.println("Temp: "+(String)temperatura+ " ; Humidity: " + humedad); 
            delay(1000);
   
}
