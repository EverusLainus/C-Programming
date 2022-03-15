#include <stdio.h>

int main ()
{
    int a = 85;
    int b = 20;
     int Average;

      Average = a/b;
     printf("Total working hours per month is %d \n", a);
     printf("Total number of working days per month is %d \n", b);
     printf("Average working hours per day is %d \n", Average);
     
     float Avg = a/(float)b;
     printf("more precise average working hours per day is %f ", Avg);
     

     float avg = (float)a/b;
     printf("precise average working hours per day is %f", avg);
return 0;
}