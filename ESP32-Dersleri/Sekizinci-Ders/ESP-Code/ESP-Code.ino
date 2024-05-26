#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

const char* ssid = "Fatih-Bedirhan-2";
const char* password = "Fadbed2020";

const char* mqtt_server = "192.168.1.100";
const int mqtt_port = 1883;

const char* gondericiTopic = "esp32/gonderici";
const char* aliciTopic = "esp32/alici";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("WiFi bağlanıyor: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi bağlandı");
  Serial.println("IP Adresi: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mesaj geldi [");
  Serial.print(topic);
  Serial.print("] ");

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("MQTT sunucusuna bağlanılıyor...");
    
    if (client.connect("ESP32Client")) {
      Serial.println("Bağlandı");
      client.subscribe(gondericiTopic);
    } else {
      Serial.print("Bağlantı hatası, tekrar deneyecek: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

unsigned long previousMillis = 0;
const long interval = 5000; // 5000 milisaniye (5 saniye)

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Belirli aralıklarla veri gönderme
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    String message = "Merhaba MQTT";
    Serial.print("Mesaj gönderiliyor: ");
    Serial.println(message);
    client.publish(aliciTopic, message.c_str());
  }
}
