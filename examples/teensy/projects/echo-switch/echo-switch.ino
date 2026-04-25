#include <Audio.h>
#include "MyDsp.h"

//#define HIGH 

MyDsp myDsp;
AudioInputUSB in;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(in,0,myDsp,0);
AudioConnection patchCord1(in,1,myDsp,1);
AudioConnection patchCord2(myDsp,0,out,0);
AudioConnection patchCord3(myDsp,1,out,1);

void setup() {
  pinMode(A2, INPUT_PULLUP); //button
  pinMode(1, OUTPUT);
  AudioMemory(12);
  audioShield.enable();
  audioShield.volume(0.5);
}

void loop() {
  static bool lastBtn=HIGH;
  static bool effect;
  bool led;
  bool crtBtn=digitalRead(0);
  if(lastBtn==HIGH && crtBtn==LOW)
  {
        led=!effect;
        digitalWrite(1, led);
        delay(50);
        effect=!effect;
  }
  myDsp.btn=!effect;

  lastBtn=crtBtn;

}
