#include <Audio.h>
#include "MyDsp.h"

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

int state;

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
  pinMode(0, INPUT);
}

void loop() {
  float potValue=analogRead(A0)/1023.0*1950.0 + 50.0;
  float volume=analogRead(A2)/1023.0;
  myDsp.setFreq(potValue);
  myDsp.setVolume(volume);
  Serial.println(state);
  delay(100);
}
