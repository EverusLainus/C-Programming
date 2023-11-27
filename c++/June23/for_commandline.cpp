//use for in command line

#include <iostream>
using namespace std;

void f(int a){
    cout <<a<<endl;
}

int main(){
    int a;
    cin>>a;
    f(a);
    return 0;
}
/*
to pass input to the program:

for i in {1..6}; do read value; echo "$value" | ./file_name; done;
*/