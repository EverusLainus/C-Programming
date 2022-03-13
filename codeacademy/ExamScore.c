#include <stdio.h>

int f(int x, int y)
{
    int a;
    a = x* 10 +y;
    return a;

}

int main()
{   
    int class;
    int a;
    int b;
    printf("Enter your class:");
    scanf("%d", &class);
    if (class==1)
    {
        a=f(1,2);
        printf("your exam score is %d", a);
    }
    else 
    {
        b=f(2,2);
        printf("your exam score is %d", b);
    }
return 0;
}