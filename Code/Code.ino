//volume: max = 30, min = 0
//player.playMp3Folder(teller);  // Play the "000teller.mp3" in the "mp3" folder on the SD 

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define busy 7

static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
				     //use pins 2 and 3 to communicate with dfminplayer 

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;

int teller = 1; //teller used for playing next song

void setup_serial(){
  Serial.begin(9600); //init usb serial for debugging
  softwareSerial.begin(9600); //init serial port for dfminiplayer

  if(player.begin(softwareSerial)) 
  {
    Serial.println("OK"); 
    player.volume(30);  //set volume to maximum (0 to 30)
  }
  else
  {
    Serial.println("connecting with dfminiplayer failed");
  }
}

void setup_pins(){
  pinMode(busy, INPUT);
}

void setup() {
  setup_pins(); 
  setup_serial(); 
}

void loop() {
  if (digitalRead(busy) == 1) {
    player.playMp3Folder(teller);  // Play the "000teller.mp3" in the "mp3" folder on the SD  
    Serial.println(teller);
    teller++; 
    Serial.println(teller);
    delay(3000); 
  }
  else{
  
}
