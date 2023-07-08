//construct a pointer array

#include <iostream>
using namespace std;

int main()
{
    int ** ptrarray;
    int rows;
    cout<<"Enter the number of pointers"<<endl;
    cin >>rows;
    ptrarray = new int * [rows];
    int cln=0;
    for(int i=0;i<rows;i++){
        cin>>cln;
        ptrarray[i]= new int [cln];
    }
    ptrarray[2][1]=7;
    cout <<ptrarray[2][1];
    return 0;   
}