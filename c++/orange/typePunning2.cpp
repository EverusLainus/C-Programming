//accessing the memory of the struct with pointers to other data types

#include <iostream>
using namespace std;

struct Seats{
    int a;
    int b;
};

int main(){
    Seats S={2, 6};

//to print out b in S.
    int y = *(int *)((char *)&S+4);
    /*
    (char *)&S - make the address of S a pointer to char
    (char *)&S+4- S has two integers. each has 4 bytes of memory and char
        takes a single bytes so we add 4 to reach to b.
    (int *)((char *)&S+4 - we convert the caracter pointing to the second
        integer of struct to int *
    int y = *(int *)((char *)&S+4) - dereference it to get the value
    */

    cout <<y<<endl;
    return 0;
}