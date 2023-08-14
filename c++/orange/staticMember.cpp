//two ways of initalising struct variables
//one doesnt work if a struct variable is static
#include <iostream>
using namespace std;


struct Struct{
    int a,b;

    void print(){
        cout << a <<" "<< b<<endl;
    }
};

struct static_Struct{
    static int a1,b1;

    static void print(){
        cout << a1 <<" "<< b1<<endl;
    }
};

//when a struct variable is static declare it ouside
int static_Struct::a1;
int static_Struct::b1;

int main(){
//struct with normal members
    Struct x;
    x.a=1;
    x.b=2;

    Struct y ={3 , 4};
    y.print();//prints 3 4

//struct with static members
//following works after static variable are declared globally
    static_Struct z1;
    z1.a1=7;
    z1.b1=8;
    z1.print();//prints 7 8

//correct way to do this
    static_Struct::a1=7;
    static_Struct::b1=8;
    static_Struct::print();

//    static_Struct z ={5 , 6};//this initialisation is not possible


    return 0;

}