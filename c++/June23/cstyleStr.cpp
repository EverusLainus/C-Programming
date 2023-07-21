//we cannot modify the pointer to character array
#include<iostream>
using namespace std;

int main()
{
 //   string str = "Hello!"; works fine
 //stored in read only memory
    char *str= "hello!";
    str[5] = '?';
    cout <<str<<endl;
    return 0;
}
/*
//warning: conversion from string literal to 'char *' is deprecated
bus error
*/