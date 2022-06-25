#include <stdio.h>
#include <stdlib.h>

typedef struct cube
{
int length;
int breath;
int height;
}cube;//name the struct as cube

//while passing struct as argument no need to mention "struct"
float CubeArea(cube mycube){
 return mycube.length* mycube.breath* mycube.height;
}


int main()
{
    //name struct as myCube
    struct cube myCube;
    myCube.length = 2;
    myCube.breath= 7;
    myCube.height = 12;
    float area = CubeArea(myCube);
    printf("area is %f\n", area);
    return 0;
}