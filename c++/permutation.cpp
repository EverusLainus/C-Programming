#include <iostream>
using namespace std;

int main()
{
    int a=0;
    int b=0;
    int c=0;
    cout << "enter a sequence of three numbers"<< endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << "("<<a <<", "<<b<<","<< c<<")" << endl;
    cout << "("<<a <<", "<<c<<","<< b<<")" << endl;
    cout << "("<<b <<", "<<c<<","<< a<<")" << endl;
    cout << "("<<b <<", "<<a<<","<< c<<")" << endl;
    cout << "("<<c <<", "<<a<<","<< b<<")" << endl;
    cout << "("<<c<<", "<<b<<","<< a<<")" << endl;
    return 0;
}