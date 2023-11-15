//treating a struct with two integers as array of two integers

#include <iostream>
using namespace std;

struct Seats{
    int a;
    int b;
};

int main(){
    Seats S={2, 6};
    
    int * int_ptr =  (int *)&S;

    cout <<int_ptr[0]<<" "<<int_ptr[1]<<endl;
    return 0;
}