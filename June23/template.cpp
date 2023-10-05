//use template to create an array of any type and size
#include <iostream>
using namespace std;
template <typename T, int N>

class Array{
    public:
    T array[N];
};

int main(){

//array of type int and size 5
    Array<int,5> my_int_Array;

    for(int i=0; i<5; i++){
        my_int_Array.array[i]= i;
    }
    for(int i=0; i<5; i++){
        cout<<my_int_Array.array[i]<<" ";
    }
    cout<<endl;

//array of type char and size 3
    Array<char,3> my_char_Array;

    for(int i=0; i<3; i++){
        my_char_Array.array[i]= 98+i;
    }
    for(int i=0; i<3; i++){
        cout<<my_char_Array.array[i]<<" ";
    }
    cout<<endl;
    return 0;
}