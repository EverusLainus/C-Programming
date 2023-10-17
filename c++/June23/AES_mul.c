//binar 8 bit multiplication as in AES

#include <stdio.h>
#include <stdlib.h>

static const uint16_t HIGH = 0x8000;
static const uint16_t LOW = 0x1;
uint16_t multiply( uint16_t a, uint16_t b){
    uint16_t a_high_value;
    uint16_t p=0;
    for(int counter =0; counter < 8; counter++){
        if((b & LOW)==1 ){
            p = a^p;
            printf("p value is modifed to %d\n", p);
        }
        a_high_value = a & HIGH;
        a= a<<1; //shift left once in binary
        if(a_high_value == 1){
            a= a^ 0x1b;
        }
        b = b>>1;
        printf("At %d a is %d and b is %d\n", counter, a, b);
    }
    return p;
}

int main(){
    uint16_t a, b;
    scanf("%hd", &a);
    scanf("%hd", &b);
    uint16_t res = multiply(a, b);
    printf("product is %d\n", res);
    return 0;
}

