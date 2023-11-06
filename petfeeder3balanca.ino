#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include "HX711.h"                    // Biblioteca HX711 
HX711 balanca;                        // define instancia balança HX711
float calibration_factor = 42130;     // fator de calibração aferido na Calibraçao



// Reemplazar con tus credenciales de Wifi
const char* ssid     = "Pedrobolado";
const char* password = "zzhv4540";

// Inicializa Bot Telegram
#define BOTtoken  "Token bot telegram" 
#define CHAT_ID  "Chat Id do bot"

WiFiClientSecure client;

UniversalTelegramBot bot(BOTtoken, client);

void handleNewMessages(int numNewMessages) {

  for (int i=0; i<numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);

    String text = bot.messages[i].text;

    if (text == "/comida") {
      bot.sendMessage(chat_id, "quantidades \n /25g \n /50g \n /75g \n /100g \n /125g \n /150g \n /175g \n /200g");             
    }
    if (text == "/25g") {
      bot.sendMessage(chat_id, "foram colocados 25g de ração");   
      //programação de balança ate 25g          
    }
    if (text == "/50g") {
      bot.sendMessage(chat_id, "foram colocados 50g de ração");
      if(balanca.get_units() > 0.050){
        //motor para de girar
           
      }      
    }
    if (text == "/75g") {
      bot.sendMessage(chat_id, "foram colocados 75g de ração");   
      //programação de balança ate 75g          
    }
    if (text == "/100g") {
      bot.sendMessage(chat_id, "foram colocados 100g de ração");   
      //programação de balança ate 100g          
    }
    if (text == "/125g") {
      bot.sendMessage(chat_id, "foram colocados 125g de ração");   
      //programação de balança ate 125g          
    }
    if (text == "/150g") {
      bot.sendMessage(chat_id, "foram colocados 150g de ração");   
      //programação de balança ate 150g          
    }
    if (text == "/175g") {
      bot.sendMessage(chat_id, "foram colocados 175g de ração");   
      //programação de balança ate 175g          
    }
    if (text == "/200g") {
      bot.sendMessage(chat_id, "foram colocados 200g de ração");   
      //programação de balança ate 200g          
    }
                                                
    }
  }

void setup() {
  Serial.begin(9600);
  Serial.println("Balança com HX711 - celula de carga 50 Kg");            
  Serial.println("Pressione t para Tara");           // imprime no monitor serial
  balanca.set_scale(calibration_factor);             // ajusta fator de calibração
  balanca.tare();                                    // zera a Balança
  
  Serial.begin(115200);
  Serial.print("Conectado a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Muestra IP local 
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "Bot iniciado", "");
}

void loop() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

  while(numNewMessages) {
    handleNewMessages(numNewMessages);
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
  Serial.print("Peso: ");                            // imprime no monitor serial
  Serial.print(balanca.get_units(), 3);              // imprime peso na balança com 3 casas decimais 
  Serial.println(" kg");                             // imprime no monitor serial 
  delay(500) ;                                       // atraso de 0,5 segundos 
  if (Serial.available())                            // se a serial estiver disponivel
  {
    char temp = Serial.read();                       // le carcter da serial 
    if (temp == 't' || temp == 'T')                  // se pressionar t ou T
    {
      balanca.tare();                                // zera a balança
      Serial.println(" Balança zerada");             // imprime no monitor serial
    }
  }
}
  



    
