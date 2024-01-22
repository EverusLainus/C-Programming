#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 240

//strlen give one more than the actual length
//requires a null terminated string a argument. 
//it wil count till it reaches null character
//The behavior of strlen with a memory block that isn't explicitly null-terminated is undefined.

int main(){
    int len=0;
    char input[MAX];
    fgets( input, MAX , stdin);
    len = strlen(input);
    printf("length of of input is %d \n", len);
    return 0;
}