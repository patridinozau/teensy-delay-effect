#include <Audio.h>
#include "MyDsp.h"

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
  AudioMemory(12);
  audioShield.enable();
  audioShield.volume(0.5);
}

void loop() {
  bool btnPress=(analogRead(A2) == LOW);
  myDsp.btn=btnPress;
  delay(100);
}
