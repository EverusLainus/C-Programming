// the auto keyword
#include <iostream>
#include <string>
using namespace std;

string get_name(){
    return "get_name";
}

int main(){
    //hover over the variable to check its type

    int a = 2;

    auto b = 3;

    cout<< "int variable a is "<<a<<" auto variable b is "<<b<<endl;

    auto c = b;

    cout<<"auto variable assigned with integer variable is "<<c<<endl;

    auto x = "lainus";//becomes const char pointer
    auto y = 4.4f; //becomes a float

/*
//one useful use of auto- to save return types
//this use case is not recommended by the one who i learnt this from

this is useful when we have to change the return type of a function
but client dont hve to make any changes in there end
by using auto keyword

//cons
there mmight be a problem when the client code relies on the certain type of return variable
*/
    auto res = get_name();
    cout <<"res is automatically set to string type to store the return value of get_name() :"<<res<<endl;


    return 0;
}