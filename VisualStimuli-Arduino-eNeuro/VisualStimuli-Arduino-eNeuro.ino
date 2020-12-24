//links we found useful are included throughout the code; the url's were retrieved 12/12/2020

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_GFX.h> //https://learn.adafruit.com/adafruit-gfx-graphics-library
#include <Adafruit_LEDBackpack.h> //https://learn.adafruit.com/adafruit-led-backpack/downloads

// NUMBER OF LED DEVICES
const int d = 3;

// declare 3 LED matrices
Adafruit_8x8matrix matrix [d];

// input pins 
// DEPENDS ON YOUR CONTROLLER
int in1 = 7;
int in10 = 6;
int in100 = 5;
int in1000 = 4;

// center cue 
static const uint8_t PROGMEM
  center[] =
  { B00000000,
    B00000000,
    B00111100,
    B00110100,
    B00101100,
    B00111100,
    B00000000,
    B00000000 };        



void setup() {
  Serial.begin(9600);
  // address matrices 
  // DEPENDS ON YOUR DEVICES
  // read more about addressing here: https://learn.adafruit.com/adafruit-led-backpack/changing-i2c-address
  // see our documentation for the addresses we used
  matrix[0].begin(0x70);
  matrix[1].begin(0x71);
  matrix[2].begin(0x74);

  // turn on input pins
  pinMode (in1, INPUT);  
  pinMode (in10, INPUT);    
  pinMode (in100, INPUT);
  pinMode (in1000, INPUT);  

  // set the pins initially to low
  digitalWrite(in1, LOW); 
  digitalWrite(in10, LOW);
  digitalWrite(in100, LOW);
  digitalWrite(in1000, LOW);

  // set brightness of matrices
  for (int m=0; m<d; m++) {
    matrix[m].setBrightness(1);
  }  
}

void clear(){
  for (int i=0; i<d; i++) {
        matrix[i].clear();
        matrix[i].writeDisplay();
  }     
}

void display(){
  for (int i = 0; i<d; i++) {
        matrix[i].writeDisplay();  
  }
}

// turns on cues based on inputs; see our documentation for a table of input --> output table in StimCodes.png
void loop() {

  // determine input value 
  int cue0 = digitalRead(in1);
  int cue1 = digitalRead(in10) * 10;
  int cue2 = digitalRead(in100) * 100;
  int cue3 = digitalRead(in1000) * 1000;
  int cue = cue3 + cue2 + cue1 + cue0;

  switch(cue) {
    case(0): // NO INPUT, CLEAR MATRICES
      clear();
      break;
      
    case(1): // Input 1 ON
    // 8 - - 
      clear();
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON); 
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON); 
      display();
      break;

    case(10): // Input 2 ON
    // - - 8
      clear();
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON); 
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON); 
      display();
      break;

      
    case(100): // Input 3 ON
    // 2 - - 
      clear();
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;

    
    case(1000): // Input 4 ON
    // - - 2
      clear();
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;


    case(11): // Input 1 and 2 ON
    // 8 - 8
      clear();
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON); 
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON); 

      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON); 
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON); 
      display();
      break;

    case(101): // Input 1 and 3 ON
    // - 8 -
      clear();
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;

    case(1001): // Input 1 and 4 ON
    // 8 - 2 
      clear();
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON); 
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON); 

      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;

    

    case(110): // Input 2 and 3 ON
    // 2 - 8
      clear();
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);

      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON); 
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON); 
      display();
      break;

    case(1010): // Input 2 and 4 ON
    // - 2 - 
      clear();
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;

    case(1100): // Input 3 and 4 ON
    // 2 - 2
      clear();
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);

      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;

    

    case(111): // Input 1 and 2 and 3 ON
    // 2 8 - 
      clear();
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);

      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;
    

    case(1011): // Input 1 and 2 and 4 ON
    // 8 2 -
      clear();
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON); 
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[0].drawPixel(random(0,8), random(0,8), LED_ON); 

      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;

    case(1101): // Input 1 and 3 and 4 ON
    // - 8 2
      clear();
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);

      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      display();
      break;
    

    case(1110): // Input 2 and 3 and 4 ON
    // - 2 8
      clear();
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[1].drawPixel(random(0,8), random(0,8), LED_ON);

      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON); 
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON);  
      matrix[2].drawPixel(random(0,8), random(0,8), LED_ON); 
      display();
      break;

    case(1111): // ALL INPUTS ON:
    // CENTER CUE
      clear();
      matrix[1].drawBitmap(0, 0, center, 8, 8, LED_ON); 
      display();
      break;
  }
}
