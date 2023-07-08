#include <iostream>

using namespace std;

int main()
{
    char character = 'A';
    int integer = character;
    float doti = 6.7890123;
    
    int integer1 =(const int)character;
    cout <<"before casting "<<character<<endl;
    cout <<"value of integer with casting "<<integer1<<endl;
    cout <<"value of integer is "<<integer<<endl;
    return 0;
}