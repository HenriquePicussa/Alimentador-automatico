#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "picussa10";
const char* password = "muitomacho";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("Conectado ao Wi-Fi!");
}

void loop() {
  HTTPClient http;
  String pesobal = "123"; // Dados que você deseja enviar
  String peso = "100";

  // Construa a URL completa com os parâmetros
  String url = "http://192.168.0.21/alimentador/tabelalino/php/peso.php";

  // Configurar a solicitação POST com os parâmetros
  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Montar os dados para enviar
  String postData = "pesobal=" + pesobal + "&peso=" + peso;

  int httpResponseCode = http.POST(postData);

  if (httpResponseCode == HTTP_CODE_OK) {
    String response = http.getString();
    Serial.println("Resposta do servidor: " + response);
  } else {
    Serial.println("Falha na solicitação HTTP. Código de resposta: " + httpResponseCode);
  }

  http.end();
  delay(5000); // Espere 5 segundos antes de enviar novamente
}