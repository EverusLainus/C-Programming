#include <stdio.h>
#include <stdlib.h>

//to find a random number within 0 to 100
int main()
{
    int x=0;
    x=rand()%100;
    printf("a random number within 0 to 100 is %d", x);
    return 0;

}