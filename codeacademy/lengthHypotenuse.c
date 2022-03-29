#include <stdio.h>
#include <math.h>

// included math header fot function "sqrt " to work.
int main()
{
    int a;
    int b;
printf("Enter opposite side length of the triangle: \n");
scanf("%d",&a);
printf("Enter adjacent side length of the triangle:\n");
scanf("%d",&b);
int h= (a*a) + (b*b);
float c = sqrt(h );
printf("length of hypotenuse of the triangle is %f", c);
return 0;
}