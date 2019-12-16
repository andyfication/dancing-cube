#include <Adafruit_NeoPixel.h>

// ledPin
#define PIN 3                                                          
//Michrophone pin
#define MESSAGE 7

// number of leds
int num= 10;

// red,green,blue values
float r = 0;
float b = 50;
float g = 200;

// red,green,blue speed
float rvelocity = 0.2;
float gvelocity = 0.4;
float bvelocity = 0.3;

// initialising strip of led
Adafruit_NeoPixel strip = Adafruit_NeoPixel(num, PIN,NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.clear();
  // set brighness to 0
  strip.setBrightness(0);
  strip.show(); // Initialize all pixels to 'off'
  
  pinMode(MESSAGE,INPUT); // input michrophone

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // reading michrophone 
  int myData = digitalRead(MESSAGE);
  Serial.print(myData);
  // if no sound off led strip else brighness at 90
  if (myData == 0)
  strip.setBrightness(0);
  else
   strip.setBrightness(90);

// red,green blue boundries 
  if(r>255 or r<0)
   rvelocity *= -1;

   if(b>255 or b<0)
   bvelocity *= -1;

   if(g>255 or g<0)
   gvelocity *= -1;

// adding velocities to the red, green and blue colors
   r+=rvelocity;
   b+=bvelocity;
   g+=gvelocity;

// loop the led strip and update                                                                                                
  for (int i = 0; i < num ; i ++)
  {
  strip.setPixelColor(i, r, g, b);
  }
  
  strip.show(); // Initialize all pixels to 'off'

}
