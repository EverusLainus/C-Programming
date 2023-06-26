//C Program to Add Two Complex Numbers by Passing Structure to a Function

#include <iostream>
using namespace std;
//struct for a complex number

struct complex{
    int real;
    int img;
};

struct complex add(complex a, complex b){
    complex result;
    result.real=a.real+b.real;
    result.img=a.img+b.img;
    return result;
}

int main(){
    complex input1;
    complex input2;
    complex output;
    cout<<"Enter real and imaginary values of a complex number"<<endl;
    cin>>input1.real>>input1.img;
    cout<<"Enter real and imaginary values of a complex number"<<endl;
    cin>>input2.real>>input2.img;
    output =add(input1, input2);
    cout <<"Addition of given two complex numbers are: "<<output.real<<"+i"<<output.img<<endl;
    return 0;
}