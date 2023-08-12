#include <iostream>
using namespace std;

enum T { A = 4, B = -1, C };

class Int {
    public:
    T v;
    Int (T a) { v = a; }
    Int &operator++ () { 
     //"+=" is not applicable on enum type variable
     //   v +=1; 
     v=C;
        return *this; 
    }
};
// return type is << operator from ostream class
ostream &operator <<(ostream &out, Int &a){
    ++a;
    return out << a.v;
}

int main () {
    Int i = B;
    cout << i; 
    return 0;
}