//try fgets function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int main(){
    char get[MAX];
    //printf("strlen(get) is %d", MA);
    for(int i=0; i<5;i++){
        printf("i is %d\n", i);
        fgets(get, 5, stdin);
        printf("%s\n",get);
    }
     
    return 0;
}

