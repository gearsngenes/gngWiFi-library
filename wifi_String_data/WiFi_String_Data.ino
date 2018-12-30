#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <gngWiFi.h>

WiFiClient espClient;
PubSubClient client(espClient);

char* ssid = "WiFi_Name";

char* password = "WiFi_Password";

char* mqtt_server = "mqtt_host_IP_address";

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
  String DATA = (String)D1+","+(String)D2+","+(String)D3;
  WIFI_ONE.publishDataString(DATA, gngWiFi::D_SET4);
  delay(100);
}
