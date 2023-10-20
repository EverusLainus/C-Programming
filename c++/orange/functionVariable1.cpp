//treating function as a variable

#include <iostream>
using namespace std;

int print_function(){
    cout<< "God is Great!\n"<<endl;
    return 9;
}

int main(){

//created a variable of : type int(<function_name>)()
    int(*function)();
    //if it takes a int as parameter 
    //int(*fuction)(int); 

    function = print_function;

    //can also be writen as int(*fuction)() = store_print_function;

    //has type int (* print_function)()
    function();



    return 0;
}