#include <cmath>

#include "Smooth.h"

Smooth::Smooth() : 
del(0.0),
b1(0.0){}

void Smooth::setB1(float b){
  b1 = b;
}
    
float Smooth::tick(float input){
  float output = input + del*b1;
  del = input;
  return output*0.5;
}
