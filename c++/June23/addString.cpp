#include <iostream>
#include <string>
using namespace std;
//we cannot add two literals
//we can add two chracters to a int 
int main(){
    string str1="a";
    string str2="b";
    int str3='a'+'b';//195
    string str4=str1+str2;
    cout <<str3<<" "<<str4;
    return 0;
}