 #include <ArduinoHttpClient.h>
#include <WiFi.h>

const char* ssid     = "Redmi Note 11 Pro+ 5G";
const char* password = "152436hp";

WiFiServer server(80);

void setup()
{
    Serial.begin(9600);
       Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

void loop(){

 if (WiFi.status() == WL_CONNECTED) {
        localhost.get("php\gravar.php");

        if (localhost.responseStatusCode() == 200) {
            String response = localhost.responseBody();
            Serial.println("Resposta do servidor: " + response);
            // Faça o processamento da resposta aqui
        }
 }
}