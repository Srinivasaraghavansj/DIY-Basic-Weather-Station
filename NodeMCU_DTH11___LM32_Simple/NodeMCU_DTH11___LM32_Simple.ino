#include "DHT.h"
#define DHTPIN D2
#define DHTTYPE DHT11 
#define LM32PIN A0
DHT dht(DHTPIN, DHTTYPE);
long lastMillis = 0;
void setup(){
    Serial.begin(115200);
    dht.begin();
    pinMode(LM32PIN, INPUT);
    delay(10);
}
void loop(){


      float humedad = dht.readHumidity();
      float temperatura = dht.readTemperature();
      float temp2 = (float)analogRead(LM32PIN)/1023*3.3*0.864*100;
      
            lastMillis = millis();
            Serial.println("Temp: "+(String)temperatura+ " ; Humidity: " + humedad + "  Temp2: " + temp2); 
            delay(1000);
   
}
