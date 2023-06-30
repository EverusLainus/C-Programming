#include <iostream>
using namespace std;

void sqr_Val(int x){
    x=x*x;
}
void sqr_Ref(int& x){
    x=x*x;
}

int main(){
    int a=0;
    cout <<"call by value, Enter a number:  "<<endl;
    cin >> a;     
    sqr_Val(a);
    cout<< "the square is "<< a<<endl;
    int b=0;

    cout <<"call by reference, Enter a number: "<<endl;
    cin>>b;
    sqr_Ref(b);
    cout<< "the square is "<< b<<endl;
    return 0;
}