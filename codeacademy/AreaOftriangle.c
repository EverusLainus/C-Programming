#include <stdio.h>

float Area_triangle(float x, float y)
{
    float A= (1/(float)2)*x*y;
    return A;
}

struct triangleArea
{
    float base;
    float height;
};
int main()
{
    float b;
    float h;
    float area;
    printf("Enter the base and height of the triangle: " );
    scanf("%f",&b);
    scanf("%f", &h);
    struct triangleArea mytriangle;
    mytriangle.base=b;
    mytriangle.height=h;
    area = Area_triangle( b, h);
    printf("Area of the triangle is %f",area);
return 0;

}