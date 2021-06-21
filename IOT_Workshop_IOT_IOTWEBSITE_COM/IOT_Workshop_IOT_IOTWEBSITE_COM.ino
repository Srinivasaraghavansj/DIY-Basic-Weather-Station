//DHT Sensor
#include "DHT.h" 
#define DHTPIN 6
#define DHTTYPE DHT11 
#define BUTTONPIN 2
DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
dht.begin();
delay(100);
pinMode(BUTTONPIN, INPUT);
}

void loop() {
String humidout = (String)dht.readHumidity();
String tempout = (String)dht.readTemperature();
bool buttonstate = false;
if(digitalRead(BUTTONPIN) == HIGH)
  buttonstate = true;
else 
  buttonstate = false;
  delay(1500);
//Serial.println(" Humidity= "+(String)humidout+ "%  Temperature= " + (String)tempout + " `C  Button= " + (String)buttonstate);
String outtt = "Sensor wosms.php?client=iot2k18010&s1="+((String)humidout)+"&s2="+((String)tempout)+"&s3="+((String)buttonstate)+"&s4=NA&s5=NA#";
Serial.write(outtt);
//Serial.println(outtt);
}
