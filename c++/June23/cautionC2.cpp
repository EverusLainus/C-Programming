//some errors

#include<iostream>
using namespace std;

int main(){

//caution 1
    int a,b,c;
    a=2/1 * 2/1;
    b=2/(1 * 2)/1;
    c=(2/1 )* (2/1);
    //cout << "value of a , b, c is "<<a<<" "<<b <<" "<<c<<endl;

//caution 2
    //str takes only the character till it first meets "\0"
    //rest is lest out
    char str[]="hello\0world\0";//prints "hello"
    //cout <<str<<endl;
    char str1[]="hello world\0";//prints "hello world"
    //if no "\0" prints all inside quotes
    char str2[]="hello world";//prints "hello world"

//caution 3
    //add and sub has same level of precedence 
    //so it operates from left ot right
    int x,y,z;
    x=1-0+1;
    y=1-(0+1);
    z=(1-0)+1;
    int z1=1+(-0+1);
    int z2=1-1+1;
    int z3=(1-1)+1;//left to right or sub then add
    int z4=1-(1+1);// by bodmas or add then sub 
    //cout << "value of x , y, z is "<<x<<" "<<y <<" "<<z<< " "<<z<<endl;
    //cout << "value of z2 , z3, z4 is "<<z2<<" "<<z3 <<" "<<z4<< endl;

//caution 4
    int Int=2;
    //first decrements Int and checks if it is 2
    if(--Int==2){
        //cout<<Int<<endl;
        //prints 1
    }
    else{
        //cout <<--Int<<endl;//prints 0
    }

//caution 5
    int a1=1,b1=1,c1=1,i1=1;
    //(b1<a1)? 1; 0 and ((b1<a1)<c1)? 1; 0 
    i1=(b1<a1<c1);
    cout <<"i1 is "<<i1<<endl;

    return 0;
}

/*
value of a , b, c is 4 1 4
*/