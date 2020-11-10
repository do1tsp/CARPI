// pixelscolor soll von PI  gesteuert werden, 
// Daten sollen gespeichert werden im EEPROM sodas eine Datenverbinung nur bei Veraenderung
// aufgebaut werden muss 
// Verbaut werden 5 Segmente 
// Segment 1: Linke Tuer
// Segment 2: Fahrer 
// Segment 3: Beifahrer
// Segment 4: Rechte Tuer 
// Segment 5: Mittlere Leuchte Hier werden High-Power Dots verwendet WS2812b

#include <Adafruit_NeoPixel.h> //Libary extra einbinden
#include <avr/power.h> 

#define PIN            6
#define NUMPIXELS      10

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;

void setup() {
  pixels.begin();
}

void loop() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,255,255)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}