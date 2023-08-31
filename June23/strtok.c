#include <stdio.h>
#include <string.h>

#define MAX 240

int main(){
//parse
char buffer[]= "hey hi hello";
char limit[]=" ";

char buffer0[MAX];
char *str_ptr;
    fgets(buffer0, MAX, stdin);//get all and stop at newline
    printf("%s", buffer0);
    str_ptr = strtok(buffer0, limit);
    while(str_ptr != NULL){
        printf("s:");
        printf("%s\n", str_ptr);
        str_ptr= strtok(NULL, limit);
    }
    printf("splited string with space\n");  
    return 0;
}