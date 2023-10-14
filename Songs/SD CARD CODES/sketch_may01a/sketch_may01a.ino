//-----------------------------------------------------------------------
//DFPlayer: Mini mp3 Player
//Library by: Angelo qiao: https://github.com/DFRobot/DFRobotDFPlayerMini
//-----------------------------------------------------------------------
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
//---------------------------------------------------
SoftwareSerial softwareSerial(10, 11);
DFRobotDFPlayerMini player;
//===========================================================
void setup()
{
  pinMode(2,INPUT); pinMode(3,INPUT); pinMode(4,INPUT);
  pinMode(5,INPUT); pinMode(6,INPUT); pinMode(7,INPUT);
  pinMode(9,OUTPUT);
  //---------------------------------------------------
  softwareSerial.begin(9600);
  player.begin(softwareSerial);
}
//===========================================================
void loop()
{ player.next();
 
  if(digitalRead(5) == HIGH) player.volumeUp();
  if(digitalRead(6) == HIGH) player.volumeDown();
  //---------------------------------------------------
  if(digitalRead(2) == HIGH)
  {
    delay(200); player.next();
  }
  //---------------------------------------------------
  if(digitalRead(3) == HIGH)
  {
    delay(200); player.previous();
  }
  //---------------------------------------------------
  if(digitalRead(4) == HIGH)
  {
    delay(200);
    digitalWrite(9, HIGH);
    while(1)
    {
      player.pause();
      if(digitalRead(4) == HIGH) {player.start(); break;}
    }
    digitalWrite(9, LOW);
  }
}
