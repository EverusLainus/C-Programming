//treating function as a variable - an useful way

#include <iostream>
using namespace std;

int print_function(){
    cout<< "God is Great!\n"<<endl;
    return 9;
}

int main(){

/*
//this is a confusing type so people use alias or typedef
//prefered by instuctor is typedef
    int(*function)();
    function = print_function;
*/

//has function type name print_function
    typedef int(*function)();

//here f is a variable
    function f = print_function;

//this works
    f();

    return 0;
}