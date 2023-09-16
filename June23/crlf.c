#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 420

int main(){
    char buff[MAX];
    fgets(buff, MAX, stdin);
    char *sep =NULL;
    const char *CRLF ="\r\n\r\n";
    printf("len of crlf is %lu\n", strlen(CRLF));
    const char *LF = "\n\n";
    const char *sep_flag = NULL;

    sep = strstr(buff, CRLF);
    printf("sep is %s\n", sep);

    if(NULL == sep){
        sep = strstr(buff, LF);
       if(NULL == sep){} //return 1;
        else{
            sep_flag = LF; 
        }   
    }
    else {
        sep_flag =CRLF;
    }

    printf("getchar \n");
   //getchar();
    //getchar();
    while(getchar()=='\n'){
        while(getchar()=='\n'){
        getchar();
        }
    }
    return 0;
}