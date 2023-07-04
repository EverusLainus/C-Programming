#include <iostream>

using namespace std;
float f(int a){
    a*=a;
//convert signed integer to scalar single precision floatin point value
    return a;
}

int main(){
    float Float =8.9345;
    //convert scalar single precision floating point value to signed integer
    //conversion happen before preparing args to call f

    float result = f(Float);
    cout <<result;
    return 0;
}