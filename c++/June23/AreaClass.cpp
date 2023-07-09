//Write a program to print the area of a rectangle by creating 
//a class named 'Area' having two functions. First function named as 
//'setDim' takes the length and breadth of the rectangle as parameters and 
//the second function named as 'getArea' returns the area of the rectangle.
//Length and breadth of the rectangle are entered through keyboard.
#include <iostream>
using namespace std;

class Area{
    int Length;
    int Breadth;

    public:
    void setDim(){
        cout<<"Enter the value of Length: "<<endl;
        cin>>Area::Length;
        cout<<"Enter the value of Breadth: "<<endl;
        cin>>Area::Breadth;
    }
    long getArea(){
        return (Area::Length * Area::Breadth);
    }
};

int main(){
    Area rectangle;
    rectangle.setDim();
    long area = rectangle.getArea();
    cout <<"Area of Rectangle is "<<area<<endl;
    return 0;
}