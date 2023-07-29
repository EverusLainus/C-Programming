#include <iostream>
using namespace std;

class Stack{
    public:
   int *stackstore;
    int stack_ptr;

    Stack(int size){
        stackstore = new int[size];
        stack_ptr=0;
    }

    void Push(int value){
        stackstore[stack_ptr++]=value;
    }

    int Pop(){       
        return stackstore[--stack_ptr];
    }
    //void operator<< (int value)
    Stack& operator<< (int value){
        Push(value);
        return *this;//this is the pointer point to this object
        //we return its address.
    }

//   void operator>> (int &val
//   void operator>> (int &val){
//      val= Pop();
//   }

//we cannot overload functions distinguished by return type
    Stack& operator>> (int &val){
        val= Pop();
        return *this;
    }
};

int main(){
    Stack my_stack(3);
    my_stack << 3;
    my_stack<<3*4;
    int var =9;
    my_stack << var;

    int i,j;
//    my_stack >> i ;
//    my_stack >> j;//when return type is void
    my_stack >> j>>i;//after changing the return type to stack&
//  cout << my_stack.Pop();
    cout<< i<<" "<<j;
    return 0;
}