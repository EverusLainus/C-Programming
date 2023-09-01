#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 240

//strlen give one more than the actual length

int main(){
    int len=0;
    char input[MAX];
    fgets(input, MAX , stdin);
    len = strlen(input);
    printf("length of of input is %d \n", len);
    return 0;
}