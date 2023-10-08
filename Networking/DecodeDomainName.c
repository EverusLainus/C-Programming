#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512

//replace any other character other than a to z and '-' with dot.
void decode_domain_name(char *buffer){
    char domain[MAX];
    memset(&domain, 0, MAX);
    int len=0;
    int i = 1;
    domain[0] = '0';
    char c;

    while((buffer)[i] != 0){
        len++;
         c = (buffer)[i];
        if(( c >='a' && c <= 'z') || c == '-'){
            domain[i] = c;
        }
        else{
            domain[i] = '.';
        }
        i++;
    }
    //printf("the decoded domain name : %s\n", domain);
    for(int j=1; j<len; j++){
        printf("%c", domain[j]);
    }
}

int main(){
    char buffer[MAX];
    memset(&buffer, 0, MAX);

    scanf("%s", buffer);
    printf(" domain name : %s\n", buffer);

    decode_domain_name( buffer);

    return 0;
}

/*

3foo3bar3com0
3www3google3com0

*/