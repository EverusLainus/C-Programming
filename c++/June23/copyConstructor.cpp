//Copy Constructors 

#include <iostream>
using namespace std;

class Class{
    public:
    int value;
    Class(){
        this->value =1;
    }
    //copy constructor
    Class(Class const &source){
        value=source.value+100;
    }

};

class Class0{
    public:
    int value;
    Class0(){
        this->value=200;
    }
};

int main(){
    Class object1;
//object2 is object1 + the additional changes
//fromt the copy constructor
//builts new copied object
    Class object2(object1);

    Class0 object01;
//copies the value
//makes object02 same as object01
    Class0 object02=object01;

    cout << object2.value << endl;
	cout << object02.value << endl;

    return 0;
}