// usage of malloc 
#include <iostream>
using namespace std;

int main(){
//malloc stores in_heap in heap
    int* in_heap;
    in_heap=(int *)malloc(sizeof(int));
    cout <<"in_heap is " << in_heap <<endl;

// stored in stack normally
    int  Number=9;
    int *in_stack = &Number;
    cout <<"in_stack is " << in_stack <<endl;

//tell "new" an address to allocate
    int *num= new int;
    int *here = new(num) int;

    cout << "new allocates "<< here <<" in "<<num<<endl;
    //new allocates 0x1346069e0 in 0x1346069e0 - output
    //num and here are in same location

    delete in_heap;
    delete num;

    return 0;
}