#include <HX711.h>
#include <Stepper.h>
#include <WiFi.h>

const char* ssid     = "";
const char* password = "";

#define pinDT  22
#define pinSCK  23
#define escala 1828888.0f
HX711 scale;
float medida=0;
const int stepsPerRevolution = 2050; 
Stepper myStepper(stepsPerRevolution, 19, 18, 17, 16);

WiFiServer server(80);

void setup()
{
    Serial.begin(57600);
    scale.begin(pinDT, pinSCK);
    scale.set_scale(escala);
    scale.tare(); // ZERANDO A BALANÇA PARA DESCONSIDERAR A MASSA DA ESTRUTURA
    myStepper.setSpeed(5);

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
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
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
        scale.power_up(); // LIGANDO O SENSOR
        delay(100);
        medida = scale.get_units(5); // SALVANDO NA VARIAVEL O VALOR DA MÉDIA DE 5 MEDIDAS
        Serial.println( );
        Serial.println(medida,3);
        delay(1000);
        scale.power_down();
        }
        if (currentLine.endsWith("GET /L")) {
          myStepper.step( 2 * (stepsPerRevolution / 2) );;// MOTOR GIRAR // VALOR SERA TROCADO PARA MAIOR PRECISAO COM CADA RAÇÃO


        }
      }
    }
    client.stop();
  }
}
