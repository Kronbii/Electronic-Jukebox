#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h>

static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 10; // Connects to module's TX 

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
Servo swan;

// Create the Player object
DFRobotDFPlayerMini player;

void setup() {
  
  // Init USB serial port for debugging
  Serial.begin(9600);
  
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

}

void loop() {
swan.attach(3);
swan.write(88);
  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    // Set volume to maximum (0 to 30).
    player.volume(10);
    // Play the first MP3 file on the SD card
    player.play(1);
  } 
  delay(110000);
  swan.detach();
  delay(3000);
}
