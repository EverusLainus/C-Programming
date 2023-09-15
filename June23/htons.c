//#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>

int main(){
    uint16_t num = htons(1122);
    printf("num in host byte order is: %x\n", num);
    printf("num in host byte order is: %d\n", num );
    printf("num in host byte order is: %ul\n", num);
    return 0;
}