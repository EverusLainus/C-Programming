//catch header

#include <iostream>
using namespace std;

void throwing(int i){
    switch(i){
        case 0:
        throw 1;
        break;
        case 1:
        throw 2;
        break;
        case 2:
        throw 3;
        break;
    }
}

void throwing1(int i){
    switch(i){
        case 0:
        throw domain_error("4");
        break;
        case 1:
        throw string("3");
        break;
        case 2:
        throw exception();
        break;
    }
}

int main(){
    for(int i=0; i<3;i++){
        try{
//            throwing(i);
              throwing1(i);
        }
//i catch object compartible with exception class
        catch(exception exp){
            cout <<"exception :"<<exp.what()<<endl;
        }
//i'm Ellipsis, i catch everything
        catch(...){
            cout <<"exception caught"<<endl;
        }

    }
    return 0;
}