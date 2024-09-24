#include <ESP8266WiFi.h>
#include <DHT.h>
#include <PubSubClient.h>
#include <string.h>

#define DHT_TYPE    DHT11
#define DHT_PIN     5 // D1
#define LAMP        LED_BUILTIN

#define MQTT_SERVER "BROKER_IP_ADDRESS"
#define SSID        "SSID"
#define PASSWD      "PASSWD"

DHT dht (DHT_PIN, DHT_TYPE);

float bTemperature = 0;
float bHumidity    = 0;

long now = millis();
long lastMeasure = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void blinkLed(int timeBlink){
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(timeBlink);                        
  digitalWrite(LED_BUILTIN, LOW);   
  delay(timeBlink);
}

void setupWireless(void){
  String nodeHostname = "ESP8266-Node";

  Serial.println("[WIFI] Connecting to: ");
  Serial.println(SSID);
  
  WiFi.hostname(nodeHostname.c_str());
  WiFi.begin(SSID, PASSWD);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    blinkLed(250);
  }  
  Serial.println("");

  digitalWrite(LED_BUILTIN, LOW);
  Serial.print("[WIFI] Connected - IP Address: ");
  Serial.println (WiFi.localIP());  
}

float readTemperature(void){
  float temperature = dht.readTemperature();

  if(!isnan(temperature)){
    bTemperature = temperature;
    Serial.print("Current temperature = ");
    Serial.println(temperature);

    return temperature;
  }
  else{
    Serial.print("Current temperature = ");
    Serial.println(bTemperature);

    return bTemperature;
  }
}

float readHumidity(void){
  float humidity = dht.readHumidity();

  if(!isnan(humidity)){
    Serial.print("Current humidity = ");
    bHumidity = humidity;
    Serial.println(humidity);

    return humidity;
  }
  else{
    Serial.print("Current humidity = ");
    Serial.println(bHumidity);

    return bHumidity;
  }  
}

void zOSCallback(String topic, byte* payload, unsigned int lenght){
  Serial.println("Lenght: ");
  Serial.println(lenght);

  Serial.println("Topic: ");
  Serial.println(topic);   

  char decodedPayload[lenght];

  if(topic == "room/lamp"){
    for (int i = 0; i < lenght; i++)
    {
        decodedPayload[i] = (char)payload[i];
    }
    
    if(strncmp ((const char *) decodedPayload, "on", lenght)){
        digitalWrite(LAMP, HIGH);
    }
    else if(strncmp ((const char *) decodedPayload, "off", lenght)){
        digitalWrite(LAMP, LOW);
    }
    
  }  

}

void setup() {  
  Serial.begin(115200);
  
  pinMode(LAMP, OUTPUT);  
  dht.begin();
  setupWireless();
    
  client.setServer(MQTT_SERVER, 1883);
  client.setCallback(zOSCallback);
}

void MQTTConnection(void){
  while(!client.connected()){
    Serial.println("MQTT Connecting");
    blinkLed(700);

    if(client.connect("ESP8266-Node")){
      client.subscribe("room/lamp");      
    }  
    else{
      Serial.print("Error [");
      Serial.print(client.state());
      Serial.print("]");
      Serial.println();
      Serial.println("Failed to connect, retrying in 5 seconds");
    }
  }
}

void loop() { 
  if(!client.connected()){
    MQTTConnection();
  }
  if(!client.loop()){
    client.connect("ESP8266-Node");
  }

  now = millis();

  if(now - lastMeasure > 5000){
    lastMeasure = now;
    
    float temperature = readTemperature();
    float humidity = readHumidity();
    
    static char strTemperarure[7];
    static char strHumidity[7];

    dtostrf(temperature, 6, 2, strTemperarure);
    dtostrf(humidity, 6, 2, strHumidity);
    
    client.publish("room/temperature", strTemperarure);
    client.publish("room/humidity", strHumidity);    
  }
}