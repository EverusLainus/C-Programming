#include <stdio.h>
#include <stdlib.h>
typedef struct trio
{
int x;
int y;
int z;
}trio;

//as argument point to input to change its values
trio shuffle(trio * input){
    int temp1;
    temp1 =(*input).x;
    //int * temp2 = input.y;
    (*input).x = (*input).y;
    printf(" its %d\n", (*input).x);
    (*input).y = (*input).z;
    printf(" its %d\n", (*input).y);
    (*input).z =  temp1;
    printf(" its %d\n", (*input).z);
    return *input;
}

 int main()
 {

    trio input;//struct with 3 ints
    printf("enter three numbers:\n");
    scanf("%d", &((input).x));
    scanf("%d", &((input).y));
    scanf("%d", &((input).z));
    trio output = shuffle(&input);
    printf("after suffling we have %d, %d, %d\n",(input).x,(input).y,(input).z );
    return 0;

 }