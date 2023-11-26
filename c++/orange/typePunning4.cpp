//treating a struct with two integers as array of two integers

#include <iostream>
using namespace std;

struct Seats{
    char a;
    char b;
};

int main(){
    Seats S={'a', 'b'};
    
    char * char_ptr =  (char *)&S;

    cout <<char_ptr[0]<<" "<<char_ptr[1]<<endl;
    return 0;
}