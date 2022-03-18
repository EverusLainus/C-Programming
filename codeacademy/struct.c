#include <stdio.h>

//method_1
struct rect_t1
{
int length;
float breath;
};

//method_2
struct rect_t2
{
int length;
float breath;
};
typedef struct rect_t2 rect_tag2;

//method_3
typedef struct rect_t3
{
int length;
float breath;
}rect_tag3;
 
int main()
{
//method 1
struct rect_t1 myrect1;
myrect1.length=1;
myrect1.breath=1.5;
printf("Area of the first rectangle is %f \n", myrect1.length* myrect1.breath );

//method 2
rect_tag2 myrect2;
myrect2.length=2;
myrect2.breath=2.5;
printf("Area of the second rectangle is %f \n", myrect2.length* myrect2.breath );

//method 3
rect_tag3 myrect3;
myrect3.length=3;
myrect3.breath=3.5;
printf("Area of the third rectangle is %f \n", myrect3.length* myrect3.breath );
return 0;
}