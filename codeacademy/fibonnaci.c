#include<stdio.h>
#include<stdlib.h>
/*
fib(0)=0; fib(1)=1; n>1 fib(n)=fib(n-1)+fib(n-2);
 n<0 and odd fib(n)=fib(-n); n<0 and even fib(n)=-fib(-n)
*/
int fibonacci(int n)
{
    if(n==0|| n==1){
        return n;
    }
    else if(n>1){
        return fibonacci(n-1)+fibonacci(n-2);
    }
    else {
        if(n%2 == 0){
            return fibonacci(-n)*(-1);
        }
        else{
            return fibonacci(-n);
        }
    }
}

int main()
{
 int a;
 printf("enter an integer:");
 scanf("%d", &a);
 int x= fibonacci(a);
 printf("Fibonacci of %d is %d", a, x);
 return 0;
}