
#include<gngWiFi.h>
gngWiFi::gngWiFi(WiFiClient espClient3, PubSubClient client3,char* ssid3, char* password3, char* mqtt_server3): espClient1(espClient3), client1(client3), ssid1(ssid3), password1(password3), mqtt_server1(mqtt_server3) {
  
};



void gngWiFi :: wifiSetup()
{
  //-------------------WiFiSetup
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid1);

  Serial.print("SSID:"); Serial.println(ssid1);
  Serial.print("PASSWD:"); Serial.println(password1);
  WiFi.begin(ssid1, password1);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  //-------------------------------

  Serial.print("MQTT SERVRER:");      Serial.println(mqtt_server1);
  //computeMQTTIPaddress();
  Serial.print("MQTT SERVRER:");      Serial.println(mqtt_server1);

  Serial.print("In Wifi Setup2()");
  Serial.print("MQTT:"); Serial.println(mqtt_server1);

  client1.setServer(mqtt_server1, 1883);
  //client.setCallback(callback);
}


void gngWiFi :: reconnect() {
  // Loop until we're reconnected
  while (!client1.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client1.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client1.publish("outTopic", "hello world");
      // ... and resubscribe
      client1.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client1.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(500);
    }
  }


  client1.subscribe("testtwo");
  Serial.print("subscribed to"); Serial.println("testtwo");
}

void gngWiFi::callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

}

/*void gngWiFi::publishDataDouble(double data, int set){
  if (!client1.connected()) {
    reconnect();
  }
  client1.loop();
  
  //getADSInfo();
  //runmaxmin();
  
  String Data = (String)(data);
  if(set==D_SET1){
    Data.toCharArray(_d1, 300);
    client1.publish("/test3", _d1);
  }
  if(set==D_SET2){
    Data.toCharArray(_d2, 300);
    client1.publish("/test4", _d2);
  }
  if(set==D_SET3){
    Data.toCharArray(_d3, 300);
    client1.publish("/test5",_d3);
  }
  if(set==D_SET4){
    Data.toCharArray(_d4, 300);
    client1.publish("/test6",_d4);
  }
}*/

void gngWiFi :: publishDataString(String str,char* topic) {
  
  if (!client1.connected()) {
    reconnect();
  }
  client1.loop();
  
  str.toCharArray(_d, 300);
  client1.publish(topic, _d);
}