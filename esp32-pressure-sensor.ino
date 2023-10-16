/*
ESP32 Turbidity Sensor
by Roland Pelayo
for TeachMeMicro

Rev 1.0 - October 22, 2023

Full tutorial on https://www.teachmemicro.com/esp32-pressure-sensor
*/
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "mainpage.h"
#include "jscript.h"
#include "HX710B.h"

const int DOUT_Pin = 25;   //sensor data pin
const int SCK_Pin  = 17;   //sensor clock pin

//provide your own WiFi SSID and password
const char* ssid = "Stacey's_Wifi_2.4";
const char* password = "vJKQ5dsp";

WebServer server(80);

HX710B pressure_sensor; 

//For storing data as string
String text= "";
//Sensor data
double pressure;

void setup() {
  //For debugging
  Serial.begin(9600);

  //Create pressure sensor instance
  pressure_sensor.begin(DOUT_Pin, SCK_Pin);

  //Use ESP32 as WiFi Station
  WiFi.mode(WIFI_STA);
  //Initiate WiFi Connection
  WiFi.begin(ssid, password);
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  //Print your WiFi's SSID (might be insecure)
  Serial.println(ssid);
  Serial.print("IP address: ");
  //Print your local IP address (needed for browsing the app)
  Serial.println(WiFi.localIP());
  //Page for reading data. Sensor is read in this part
  server.on("/data", [](){
    delay(100);
      if (pressure_sensor.is_ready()) {
        Serial.println(pressure_sensor.pascal());
        pressure = pressure_sensor.pascal();
      } else {
        pressure = 0.00;
      }
    text = (String)pressure;
    Serial.println(text);
    server.send(200, "text/plain", text);
  });
  //Home page. Contents of 'page' is in mainpage.h
  server.on("/", []() {
   server.send(200, "text/html", page);
  });
  //JavaScript! Contents of 'javascript' is in jscript.h
  server.on("/jscript.js", []() {
   server.send(200, "text/javascript", javascript);
  });
  //start web server
  server.begin();
  //Just stating things
  Serial.println("HTTP server started");
}

void loop() {

  //Make the ESP32 always handle web clients
  server.handleClient();
  
}
