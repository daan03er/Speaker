//volume: max = 30, min = 0
//player.playMp3Folder(teller);  // Play the "000teller.mp3" in the "mp3" folder on the SD 

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

//extra pin 
#define busy 7
<<<<<<< HEAD
#define interruptPin 2

//pins for buttons
#define pause_play_button 13
#define previous_button 12
#define next_button 11
#define stop_button 10
#define shuffle_button 9

//pins for display
#define display_data1 A0
#define display_data2 A1
#define display_data3 A2
#define display_data4 A3
#define display_enable A4
#define display_RS A5

//use pins 4 and 5 to communicate with dfminiplayer
static const uint8_t PIN_MP3_TX = 4; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 5; // Connects to module's TX

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;

volatile byte state = LOW;
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

void setup_interrupt(){
  pinMode(interrupt_pin, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), read, CHANGE); 
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

//reading the 5 individual buttons and returning the high or low boolean of every button
//since only 2 pins can be used for interrupt, all the buttons are connected to pin 2 for the interrupt and a separate pin for the data
int read_button(){
  digitalRead(
}

//function for writing or commanding to the display, with 2 parameters
//look at MP3 code blok 3 for inspiration  
void write_display(boolean RW, int info){

}

//used for interrupt function, changing the state 
void read(){
  state = !state; 
}
