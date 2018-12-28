#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <gngWiFi.h>

WiFiClient espClient;
PubSubClient client(espClient);

char* ssid = "WiFiName";

char* password = "WiFi Password";

char* mqtt_server = "Mqtt host IP address";

//INSTANTIATE
gngWiFi WIFI_ONE(espClient,client,ssid,password,mqtt_server);

double D1,D2,D3;

void setup() {
  Serial.begin(115200);
  WIFI_ONE.wifiSetup();

}

void loop() {
  D1=random(-600,600);
  D2=random(-600,600);
  D3=random(-600,600);
  Serial.println(D1);
  WIFI_ONE.publishData(D1,gngWiFi::D_SET1);
  WIFI_ONE.publishData(D2,gngWiFi::D_SET2);
  WIFI_ONE.publishData(D3,gngWiFi::D_SET3);
  delay(50);

}
