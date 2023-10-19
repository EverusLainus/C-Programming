// take a four byte string and rotate it to left

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

void rotate(uint8_t *in) {
        uint8_t a;
        a = in[0];
        for(int c=0; c<3; c++) 
            in[c] = in[c + 1];
        in[3] = a;
        return;
}

int main(){
   uint8_t in[4];

    for(int i=0 ;i< 4; i++){
        scanf("%x", &in[i]);
        printf("scaned result .%x.\n", in[i]);
    }
    rotate(in);
     for(int i=0 ;i< 4; i++){
        printf("result .%x.\n", in[i]);
    }
    return 0;
}