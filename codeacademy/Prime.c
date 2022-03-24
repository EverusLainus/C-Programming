#include <stdio.h>

int main()
{
int a;
int i;
int c=0;

// ask a number
printf("Enter a integer:");
//receive a number
scanf("%d", &a);

// check "a modulo i =0" for all i from 1 to a
for (i=1; i<=a;i++)
{
if(a%i == 0)
{
    c++;
}
}
//if c=2 then a is prime else it is not
if(c==2){
printf("%d is prime",a);
}
else{
    printf("%d is not prime",a);
}
return 0;
}