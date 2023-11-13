//get around types

#include <iostream>
using namespace std;

int main(){
    int a = 50;
    cout <<" memory address of a "<<&a<<endl;
    //value is given 8 bytes implicitely
    double value = a;
    

    //if we want to take the 4 bytes of int convert to double.
    // bad idea
    //double value = *(double*)&a;
    cout <<" memory address of value "<<&value<<endl;
    cout << value<<endl;

    return 0;
}