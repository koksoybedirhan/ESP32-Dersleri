#include "WiFi.h"

const char* ssid = "Fatih-Bedirhan-2";
const char* password = "Fadbed2020";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("WiFi'ya baglaniliyor");
  }

  Serial.println("WiFi'ya baglandi");
  Serial.print("ESP IP'si: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
