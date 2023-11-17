//accessing the memory of the struct as array

#include <iostream>
using namespace std;

struct Seats{
    int a;
    int b;

    int * get_begining(){
        return &a;
    }
};

int main(){
    Seats S={2, 6};

//to print out b in S.
    int * p = S.get_begining();


    cout <<p[1]<<", "<<p[0]<<endl;
    return 0;
}