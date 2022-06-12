#include<stdio.h>
#include<stdlib.h>

void swap(int * x, int * y){
int  temp;
 temp =*x;
printf("*temp=%d\n", temp);
*x= *y;
printf("*x=%d\n", * x);
*y= temp;
printf("*y=%d\n", * y);
}

int main()
{
 int  x_1=2;
 int y_2 =4;
int * x=&x_1;
int * y=&y_2;
printf("before swaping x=%d, y=%d\n", *x,*y);
swap(x,y);
printf("after swaping x=%d, y=%d\n", *x,*y);
return 0;
}