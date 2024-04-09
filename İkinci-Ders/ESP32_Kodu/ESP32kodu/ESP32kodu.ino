#include <WiFi.h>

//web connection
const char* ssid     = "Fatih-Bedirhan-2";
const char* password = "Fadbed2020";
const char* host = "192.168.1.103";

int IntDb = 35;
String StringDb = "Merhaba2";

void setup() {
  //starting serial communication
  Serial.begin(115200);
  WiFi.begin(ssid, password);
}

void loop() {
  delay(200);
  
  //checking connection
  WiFiClient client;
  const int httpPort = 80;

  if (!client.connect(host, httpPort)) 
  {
    Serial.println("connection failed");
    return;
  }
  
  //sending datas to server
  client.print(String("GET http://localhost/esptowebanddb/index.php?") + 
                          ("IntDb=") + IntDb +
                          ("&StringDb=") + StringDb +
                          " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    //Printing data to Serial Port Screen
    Serial.println(String("GET http://localhost/esptowebanddb/index.php?") + 
                          ("IntDb=") + IntDb +
                          ("&StringDb=") + StringDb +
                          " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    while (client.available() == 0) {
        if (millis() - timeout > 1000) {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }
  delay(5000);
}
