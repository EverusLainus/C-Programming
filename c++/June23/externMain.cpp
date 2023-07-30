#include <iostream>
#include "extern.cpp"

using namespace std;

//variable is global
//gets the variable value from an external file extern.cpp
extern int variable;

//using function name as "function"
//throws error "reference to 'function' is ambiguous"
void funct(){
    extern int fn_variable;
    cout <<"i'm a function and i copied "<<fn_variable <<" from ouside"<<endl;
}

int main(){
    //i'm not called as global variable yet
    //im able to copy main_variable from outside
    extern int main_variable;

    cout<<"i copied "<<variable <<" and "<<main_variable<<" from an external c++ file"<<endl;
    funct();
    return 0;
}