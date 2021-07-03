//volume: max = 30, min = 0
//player.playMp3Folder(teller);  // Play the "000teller.mp3" in the "mp3" folder on the SD 

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define busy 7
int teller = 1;

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

void setup() {
  pinMode(busy, INPUT); 
  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("OK");
  
    // Set volume to maximum (0 to 30).
    player.volume(30);
  }
  else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
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
}
