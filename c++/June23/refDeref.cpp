#include <iostream>
using namespace std;

int main(){
    int son=7;
    int * dad= &son;
    int ** granpa= &dad;

    cout <<"grandson of grandpa is "<<**granpa<<", who live at "<<*granpa<<endl;   
    cout <<"son of grandpa lives at "<<granpa<<endl;
    cout <<"son of dad lives at "<<dad<<endl;

    return 0;
}