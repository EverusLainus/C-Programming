
//Write a program to print the area and perimeter of a triangle 
//having sides of 3, 4 and 5 units by creating a class named 'Triangle' with 
//a function to print the area and perimeter.

#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
    private:
    int a;
    int b;
    int c;

    public:
    void set(int x, int y, int z){
        Triangle::a=x;
        Triangle::b=y;
        Triangle::c=z;
    }

    int perimeter (){
        long peri = (Triangle::a+Triangle::b+Triangle::c);
        cout <<"The Perimeter of the Triangle is : "<< peri<<endl;
        return peri;
    }

    void area (){
        double s= (perimeter()/2);
        double m =(s*(s-Triangle::a)*(s-Triangle::b)*(s-Triangle::c));
        double  heron= sqrt(m);
        cout <<"The Area of the Triangle is : "<<heron<<endl;
    }
};

int main(){
    Triangle my_triangle;
    my_triangle.set(3, 4, 5);
    my_triangle.area();
    return 0;
}