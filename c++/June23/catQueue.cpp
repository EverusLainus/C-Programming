#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <char> qu;
    int a,b;
    cout<<"Enter length of two strings: "<<endl;
    cin>> a;
    cin>> b;
    cout<<"Enter the two strings "<<endl;
    for(int i=0 ; i< a+b; i++){
        char c =0;
        cin>>c;
        qu.push(c);
    }
    for(int j=0 ; j< a+b; j++){
       char result =0;
       result = qu.front();
       cout<<result;
       qu.pop();
    }
    return 0;
}