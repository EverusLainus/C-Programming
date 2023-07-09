//Write a program to print the area of two rectangles having sides (4,5) and (5,8)
//respectively by creating a class named 'Rectangle' with a function named 'Area' which returns the area. 
//Length and breadth are passed as parameters to its constructor.

#include <iostream>

using namespace std;

class Rectangle{
    int length;
    int breadth;

    public:
    Rectangle(int a, int b){
        Rectangle::length=a;
        Rectangle::breadth=b;
    }

    int area(){
        return (Rectangle::length * Rectangle::breadth);
    }
};

int main(){
    Rectangle r1= Rectangle(4, 5);
    int a= r1.area();
    cout <<"area of triangle is :"<<a<<endl;

    Rectangle r2= Rectangle(5, 8);
    int b= r2.area();
    cout <<"area of triangle is :"<<b<<endl;
}