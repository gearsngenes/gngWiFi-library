#ifndef gngWiFi_h
#define gngWiFi_h

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class gngWiFi {
  private:
    char* ssid1;
    
    char* password1;

    char* mqtt_server1; // raspberry MQTT broker.


    WiFiClient espClient1;
    PubSubClient client1;

    
    
    char _d1[300]; // send to the browser
    char _d2[300]; // send to the browser
    char _d3[300]; // send to the browser
  
  public:
    gngWiFi(WiFiClient espClient3, PubSubClient client3, char* ssid3, char* password3, char* mqtt_server3);
    
    static const int D_SET1=1;
    static const int D_SET2=2;
    static const int D_SET3=3;
    
    void wifiSetup();
    void callback(char* topic, byte* payload, unsigned int length);
    void reconnect();
    void publishData(double data, int set);

};
#endif