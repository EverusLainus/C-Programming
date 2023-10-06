#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>

struct Rd{
    uint8_t addr[4];
};

void get_A_record(uint8_t addr[4]){
        addr[0] = 192;
        addr[1] = 168;
        addr[2] = 1;
        addr[3] = 1;
}

int main(){
    struct Rd *rd;
    rd = calloc (1, sizeof(struct Rd));
    get_A_record(rd->addr);
    for (int i = 0; i < 4; ++i){
        printf("%s%u ", (i ? "." : ""), rd->addr[i]);
    }
    printf("\n");
    
//print the condtents of the array
     for (int i = 0; i < 4; ++i){
        printf("%u ", rd->addr[i]);
    }
     printf("\n");

//prints nothing for i=0 and prints "." for i>0
    for (int i = 0; i < 4; ++i){
        printf("i is %d ",i);
        printf("%s \n", (i ? "." : ""));
    }

    return 0;     
}
