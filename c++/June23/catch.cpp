//try a kind of catch function
//catch always comes with try
//throw always orginates from try block
//if throw did not find catch with its throw type-execution error
//variable in catch-head is valid only in catch block

#include <iostream>
using namespace std;

int main (){

 //  throw 2.25; //not alone
    try{
        throw 0.1;
    }
    catch(double x){
        x*=2;
        cout <<x<<endl;
    }
    return 0;
}