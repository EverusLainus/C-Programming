#include <stdio.h>

int main()
{
//overflow. y+20000 has 16 bits in binary which cannot be stored in short which has signed and unsigened 2 bits.
short y = 30000;
short x = y + 10000;
printf("%hi \n",x);
printf("%i", y + 10000);
}