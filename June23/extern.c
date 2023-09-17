#include <stdio.h>
#include "extern1.c"

int a;//defined caz it is use in this c file

int main(){
    a=3;
    printf("value of a is %d\n", a);
    return 0;
}