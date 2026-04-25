//make each note have a different amplitude
#include <Audio.h>
#include "MyDsp.h"

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

float frequency;
int d[]={72, 40, 80, 60, 100};
float gain[]={0.1, 0.3,0.2,0.5,0.6};
int ind=0;

float mtof(float note){
return pow(2.0,(note-69.0)/12.0)*440;
}

void setup() {
  AudioMemory(2);
  audioShield.enable();
  //audioShield.volume(0.5);
}

void loop() {
  myDsp.setFreq(mtof(d[ind]));
  myDsp.setVol(gain[ind]);
  ind=(ind+1)%5;
  delay(100);
}
