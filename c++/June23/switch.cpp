#include <iostream>

using namespace std;

int main(){
    int a=2;
    int b =(a<<1);
    cout <<"b ia "<<b<<endl;
    switch(a<<2){//a is still two swich expression is not assigned to a
    //switch continuous from the right case till it encounters a break.
        case 8: 
                cout <<"value of a is "<<a <<endl;
                a++;
        case 56:
                cout <<"value of a is "<<a <<endl;
                a++;
        case 2: 
                cout <<"value of a is "<<a <<endl;
                break;
        case 1: 
                cout <<"value of a is "<<a <<endl;
                a--;
    }
    cout << a;
}