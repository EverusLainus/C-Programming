// try strcspn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 120

int main(){
    char input[MAX];
    fgets(input, MAX , stdin);
     input[strcspn(input, "\n")] = 0;

    printf("input is :%s.\n", input);
    printf("length is %lu\n", strlen(input));
    char res[MAX];
    res[0]='\\';
    res[1]='r';
    res[2]='\\';
    res[3]='n';
    //char *res = "\r\n";
    printf("length is %lu\n", strlen(res));
    printf( "%lu\n", strcspn( input, res ) );
    return 0;
}