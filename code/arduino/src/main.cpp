#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Servo.h>
#include "minikame.h"



// Wifi Access Point configuration
const char* ssid = "kame";
const char* password = "a1b2c3d4";

void parseData(String data);

MiniKame robot;
WiFiServer server(80);
bool running=0;
String input;


void setup() {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    server.begin();
    //Serial.begin(115200);
    Serial.begin(9600);

    delay(1000);
    robot.init();
}

void loop() {
    WiFiClient client = server.available();
    if (!client) {
        IPAddress myIP = WiFi.softAPIP();
        Serial.print("AP IP address: ");
        Serial.println(myIP);
        delay(1000);
    }
    while (client.connected()) {
        if (running){
            Serial.println("running");
            if (client.available()) {
                while(client.available()) input = client.readStringUntil('+');
                parseData(input);
            }
            else {
                Serial.println("Keep Moving");
                parseData(input);
            }
        }
        else{
            Serial.println("Normal mode");
            if (client.available()) {
                Serial.println("Client available");
                while(client.available()) input = client.readStringUntil('+');
                parseData(input);
            }
            else{
                robot.home();
            } 
        }
    }
    
}

void parseData(String data){

    switch (data.toInt()){

        case 1: // Forward
            robot.walk(1,550);
            running = 1;
            break;

        case 2: // Backward
            robot.zero();
            break;

        case 3: // Left
            robot.turnL(1,550);
            running = 1;
            break;

        case 4: // Right
            robot.turnR(1,550);
            running = 1;
            break;

        case 5: // STOP
            running = 0;
            break;

        case 6: // Pushups
            robot.pushUp(2,2000);
            break;

        case 7: // fire ??
            robot.upDown(4,250);
            break;

        case 8: // Jumping (not working)
            robot.jump();
            break;

        case 9: // Say Hello 
            robot.hello();
            break;

        case 10: // punch ??
            robot.frontBack(4,200);
            break;

        case 11: // Dancing Moves
            robot.dance(2,1000);
            break;

        case 12: // Moonwalk
            robot.moonwalkL(3, 1000);
            break;

        default:
            robot.home();
            break;
    }
}
