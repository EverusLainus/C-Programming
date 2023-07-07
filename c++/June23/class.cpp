//implement a stack using class
#include <iostream>
using namespace std;

class stack{
    int stackStore[25];
    int sp;//stack pointer
    public:
    //constuctor goes befor the class starts
    //assigns value of sp=0
    //constructor are in public. 
    //used to initialise.
    stack(){
        sp=0;
    }
    stack(int a){
        sp=a;
    }
    //push an integer to the top of the stack
    void push(int a){
        stackStore[++sp]= a;
    }
    //function definition of pop
    int pop(); 

}; //class ends with ;

//pop the element from the top of the stack
int stack::pop(){
    int a = stackStore[sp];
    sp--;
    return a;
}

int main(){
//  stack *mystack = new stack(45);
    stack mystack;
    mystack.push(1);
//  *(mystack).push();
//  mystack->pop
    mystack.push(2);
    int a = mystack.pop();
    mystack.push(3);
    mystack.push(4);
    cout <<a<<endl;
    a = mystack.pop();
    cout <<a;
    return 0;
}