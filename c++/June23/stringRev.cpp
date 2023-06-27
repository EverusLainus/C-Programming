// reverse a string

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int num=0;
    cout <<"Enter the length of the string: "<<endl;
    cin>> num;
    cout <<"Enter the string: "<<endl;
    stack<char> input;
    for (int i=0; i< num; i++){
        char a =0;
        cin>>a;
        input.push(a);   
    }
    while(input.size()){
        char re=0;
        re=input.top();
        input.pop();
        cout<<re;
    }
    return 0;
}