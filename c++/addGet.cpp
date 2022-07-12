#include <iostream>
using namespace std;

// Write a C++ program to check if it \
is possible to add two integers to get the \
third integer from three given integers
int main()
{
    int a=0;
    int b=0;
    int c=0;
    cout << "enter a sequence of three numbers"<< endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if(c == a+b){
        cout << "success"<<endl;
    }
    else{
        cout <<"error"<< endl;
    }
    return 0;

}