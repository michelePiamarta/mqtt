#include "WiFi.h"
const char* INDIRIZZO_BROKER = "192.168.6.73"; //non abbiamo dns

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  
}
//connetto, finchè non riesco aspetto
void connetti_wifi(){
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  WiFi.begin("BancoSperimentale2G", "Galileo19");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connesso");
  Serial.println("Indirizzo IP: ");
  Serial.println(WiFi.localIP());
}
//connetto, se non riesco aspetto 5sec e riprovo
void connetti_mqtt(){
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.subscribe("il_tuo_topic");
    } else {
      Serial.print(client.state());
      Serial.print("riprovo a connettermi");
      delay(5000);
    }
  }
}