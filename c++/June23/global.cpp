#include <iostream>

using namespace std;

//global variable
int rose = 0;
int garden(int a){
    rose +=7;
    cout <<rose<<" roses and "<<a<<" lilies"<<endl;
    return 0;
}
int main(){
    int lily=4;
    rose ++;
    garden(lily);
    return 0;
}