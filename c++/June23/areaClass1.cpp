
//Write a program to print the area of a rectangle by creating a class named
//'Area' taking the values of its length and breadth as parameters of its constructor 
//and having a function named 'returnArea' which returns the area of the rectangle. 
//Length and breadth of the rectangle are entered through keyboard.

#include<iostream>

using namespace std;

class Area{
    int length;
    int breadth;

    public:
    Area(int a, int b){
        Area::length=a;
        Area::breadth=b;
    }
    
    long returnArea(){
        return (Area::length * Area::breadth);
    }
};

int main(){
    Area a=Area(2,9);
    long result = a.returnArea();
    cout<< "Area of rectangle is : "<<result;
    return 0;
}