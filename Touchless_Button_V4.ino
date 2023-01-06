
#include "Keyboard.h"
#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    7

CRGB leds[NUM_LEDS];
//declaring button pins     
    
int prevBut = 1;

void setup() {
  pinMode(A0, INPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
  Keyboard.begin();
}                      
                
void hijau(){ 
    leds[0] = CRGB ( 0, 255, 0);
    leds[1] = CRGB ( 0, 255, 0);
    leds[2] = CRGB ( 0, 255, 0);
    leds[3] = CRGB ( 0, 255, 0);
    leds[4] = CRGB ( 0, 255, 0);
    leds[5] = CRGB ( 0, 255, 0);
    leds[6] = CRGB ( 0, 255, 0);
    FastLED.show();
}

void merah(){
    leds[0] = CRGB ( 255, 0, 0);
    leds[1] = CRGB ( 255, 0, 0);  
    leds[2] = CRGB ( 255, 0, 0);
    leds[3] = CRGB ( 255, 0, 0);                                                                    
    leds[4] = CRGB ( 255, 0, 0); 
    leds[5] = CRGB ( 255, 0, 0);
    leds[6] = CRGB ( 255, 0, 0);      
    FastLED.show();
}           
int maju;
void loop() {   
  int adc = analogRead(A0);
//  Serial.println(adc);
  int data = map(adc, 0, 1015, 0, 1);
  if (data == 0 && prevBut == 1 || data == 0) {
    Keyboard.releaseAll();
    delay(100);    
    hijau();
    delay(100);                                                                                                                                                                 
  }
  if (data == 1 && prevBut == 0 || data == 1) {
    maju = maju + 1;    
    merah(); 
    Keyboard.press(KEY_LEFT_ALT); 
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_UP_ARROW);
    delay(2000);
  }
}  
