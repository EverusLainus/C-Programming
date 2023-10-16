//treating function as a variable

#include <iostream>
using namespace std;

int print_function(){
    cout<< "God is Great!\n"<<endl;
    return 9;
}

int main(){
    //prints the address of the function
    auto store_print_function = print_function;
    cout<<"print_function is " <<store_print_function<<endl;

    auto store_print_function1 = &print_function;
    cout<<"&print_function is " <<store_print_function<<endl;

    return 0;
}