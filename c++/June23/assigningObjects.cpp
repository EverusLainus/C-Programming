#include<iostream>
using namespace std;

class X{};
class Y : public X{};
class Z : public X{};

int main(){
    Z *z =new Z();
    X *x =new X();
    Y *y =new Y();
    x=z;

//"to sub object cannot be assigned to another sub object
//even if they have same structure
//    y=x; invalid
    cout << (x==z)<<" sub object can be assigned to super object\n";
    
    return 0;
}