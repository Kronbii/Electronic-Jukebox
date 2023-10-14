#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h>

#define input A4 
static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 10; // Connects to module's TX 

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
Servo swan;

// Create the Player object
DFRobotDFPlayerMini player;

bool state;

void setup() {
  pinMode(input,INPUT);
  Serial.begin(9600); 
  softwareSerial.begin(9600);
  player.begin(softwareSerial);
}

void loop() {
swan.attach(3);
swan.write(88);
state = digitalRead(input);
Serial.println(state);

    if(state == HIGH){
      Serial.println("Awal if");
    player.volume(25);
    player.play(1);
    delay(110000);
    Serial.println("Awal end");
    }
    
    else if(state == LOW){
      Serial.println("Tene if");
    player.volume(24);
    player.play(2);
    delay(69000);
    Serial.println("Tene end");
  } 
  
  swan.detach();
  delay(3000);
}
