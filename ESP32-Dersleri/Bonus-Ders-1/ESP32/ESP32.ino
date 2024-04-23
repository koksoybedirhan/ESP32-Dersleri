#include <WiFi.h>
#include <PubSubClient.h>

// WiFi bağlantısı için SSID ve şifre
const char* ssid = "Fatih-Bedirhan-2";
const char* password = "Fadbed2020";

// MQTT sunucusu için IP adresi ve bağlantı portu
const char* mqtt_server = "192.168.1.102";
const int mqtt_port = 1883;

// MQTT istemci nesnesi oluşturma
WiFiClient espClient;
PubSubClient client(espClient);

// MQTT konusu ve mesaj
const char* topic = "test";
const char* message = "Hello from ESP32!";

void setup() {
  Serial.begin(115200);
  // WiFi bağlantısını başlatma
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // MQTT sunucusuna bağlanma
  client.setServer(mqtt_server, mqtt_port);
  while (!client.connected()) {
    Serial.println("Connecting to MQTT server...");
    if (client.connect("ESP32Client")) {
      Serial.println("Connected to MQTT server");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  // MQTT sunucusuna mesajı yayınlama
  client.publish(topic, message);
  Serial.println("Message sent");
  delay(5000); // 5 saniye bekleme
}
