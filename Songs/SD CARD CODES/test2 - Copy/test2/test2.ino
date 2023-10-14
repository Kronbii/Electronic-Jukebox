#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h>

#define input A0
static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 10; // Connects to module's TX 

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
Servo swan;

// Create the Player object
DFRobotDFPlayerMini player;
bool state;

void setup() {
  pinMode(input,INPUT);
  // Init USB serial port for debugging
  Serial.begin(9600);
  
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);
player.begin(softwareSerial);
}

void loop() {
swan.attach(3);
swan.write(88);
state = digitalRead(input);
Serial.println(state);
  // Start communication with DFPlayer Mini
 
    if(state == HIGH){
      Serial.println("fitst if");
    player.volume(10);
    // Play the first MP3 file on the SD card
    player.play(1);
    delay(110000);
    Serial.println("end");
    }
    else if(state == LOW){
      Serial.println("Second if");
       player.volume(10);
    // Play the first MP3 file on the SD card
    player.play(2);
    delay(69000);
    Serial.println("end if 2");    
  } 
  swan.detach();
  delay(3000);
}
