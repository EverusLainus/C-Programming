#include <stdio.h>

int main() 
{
const float EarthGravity =  9.8;
float LittleMacWeightonEarth = 40;
float LittleMacMass;
int planet =5;
float Weight;

LittleMacMass = LittleMacWeightonEarth / EarthGravity;

switch(planet)
{
  case 1:
Weight = LittleMacMass * 0.38;
printf("Weight is %f", Weight);
break;

case 2:
Weight = LittleMacMass * 0.91;
printf("Weight is %f", Weight);
break;

case 3:
Weight = LittleMacMass * 0.38;
printf("Weight is %f", Weight);
break;

case 4:
Weight = LittleMacMass * 2.34;
printf("Weight is %f", Weight);
break;

case 5:
Weight = LittleMacMass * 1.06;
printf("Weight is %f", Weight);
break;

case 6:
Weight = LittleMacMass * 0.92;
printf("Weight is %f", Weight);
break;

case 7:
Weight = LittleMacMass * 1.19;
printf("Weight is %f", Weight);
break;
}




}