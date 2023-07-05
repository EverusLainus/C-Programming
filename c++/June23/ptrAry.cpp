#include <iostream>
using namespace std;

int main(){
    int ** ptrToptr;
    int row =5;
    ptrToptr = new  int * [row];
    for(int i=0;i<row;i++){
        ptrToptr[i]= new int[i+1];
        for(int j=0;j<i+1;j++){
            ptrToptr[i][j]=i*j;
            cout<<ptrToptr[i][j]<<" ";
        }
        cout<<"\n";
    }
}