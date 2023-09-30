//flags in dns header



#include <stdio.h>
#include <stdlib.h>

    static int16_t OR_Mask = 0x8000;
    static int16_t Opcode_Mask = 0x7800;
    static int16_t AA_Mask = 0x400;
   static int16_t TC_Mask = 0x200;
   static int16_t RD_Mask = 0x100;
   static int16_t RA_Mask = 0x80;
   static int16_t Z_Mask = 0x70;
   static int16_t Rcode_Mask =0xF;

struct header{
    int16_t OR;
    int16_t Opcode;
    int16_t AA;
    int16_t TC;
    int16_t RD;
    int16_t RA;
    int16_t Z;
    int16_t Rcode;
};

void print_header(struct header* my_header){
    printf("my_header->OR = %u\n", my_header->OR);
    printf("my_header->Opcode = %u\n", my_header->Opcode);
    printf("my_header->AA = %u\n", my_header->AA);
    printf("my_header->TC = %u\n", my_header->TC);
    printf("my_header->RD = %u\n", my_header->RD);
    printf("my_header->RA = %u\n", my_header->RA);
    printf("my_header->Z = %u\n", my_header->Z);
    printf("my_header->Rcode = %u\n", my_header->Rcode);
}

void decode_header(int val, struct header* my_header){
    my_header->OR = (val & OR_Mask) >> 15;
    my_header->Opcode = (val & Opcode_Mask) >> 11;
    my_header->AA = (val & AA_Mask) >> 10;
    my_header->TC = (val & TC_Mask) >> 9;
    my_header->RD = (val & RD_Mask) >> 8;
    my_header->RA = (val & RA_Mask) >> 7;
    my_header->Z = (val & Z_Mask) >> 4;
    my_header->Rcode = (val & Rcode_Mask) >> 0;
}

int main(){
    struct header *my_header;
    my_header = calloc(1, sizeof(struct header));
    int value = 288;
    decode_header(value, my_header);
    print_header(my_header);
    return 0;
}