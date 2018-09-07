#include "DHT.h" 
#define DHTPIN 14
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);


#include "UbidotsMicroESP8266.h"
#define TOKEN  "A1E-jqyGydx0IpzkBDqHGgsQPRDlGV3Qhy"  // Put here your Ubidots TOKEN
#define WIFISSID "linux"
#define PASSWORD "Biswa@Fedora137"

Ubidots client(TOKEN);
unsigned long lastMillis = 0;

void setup(){
    Serial.begin(115200);
    dht.begin();
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
}
void loop(){

    if (millis() - lastMillis > 10000) {  

      float humidity = dht.readHumidity();
      float temp = dht.readTemperature();
      
            lastMillis = millis();
            client.add("humidity", humidity);
            client.add("temp", temp);
            client.sendAll(true);
            
            }
   
}
