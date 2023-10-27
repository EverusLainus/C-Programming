#include <iostream>
using namespace std;

void two_power(uint32_t num){
    uint32_t res;
    res = (num & (num-1));
    printf("res is %u\n", res);
    if(!res){
        cout<<"the given number is a power of two\n";
    }
    else{
        cout<<"the given number is not a power of two\n";
    }  
}

int main(){
    uint32_t num;
    cin>>num;
    two_power(num);
    return 0;
}

/*

n is either 0 or an exact power of two.
It works because a binary power of two is of the form 1000...000 
and subtracting one will give you 111...111. 
Then, when you AND those together, you get zero
*/