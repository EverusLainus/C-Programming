#include <iostream>
#include <vector>
using namespace std;

class vector_class{
    public:
    int vector1;
    int vector2;
    vector_class(int a=0, int b=0 ){
        vector1=a;
        vector2=b;
    }
};

//can be overloaded globally
int operator*(vector_class &V, vector_class &U){
    //'*' inside is just multiplication
    return ((V.vector1*U.vector1) + (V.vector2*U.vector2));
}

int main(){
    vector_class v1(2,3);
    vector_class v2(1,4);
    int v3;

    v3 = v1*v2;
    cout << v3 <<endl;//prints 14
    return 0;
}