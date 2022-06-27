#include<iostream>

using namespace std; 


//declare a rectangle
class rectangle{
    private:
    int length;
    int breadth;
    public:
    float area(){
        float a = this->length* this->breadth;
        return a;
    }
    //A parameters is private so \
    we make costructor inside class\
    with parameters
    rectangle(){
        this->length = 9;
        this->breadth = 9;
    }
    //B parameters are private so we make\
    constructor to take in arguments with\
    parameters.
    rectangle(int s, int t){
        this->length =s;
        this ->breadth=t;
    }
};



int main()
{


    rectangle A = rectangle();
    //A.length =7;
    //A.breadth =9;
    float area_is = A.area();
    cout << "area_is "<< area_is << " "<< endl;

    rectangle B= rectangle(4,5);
    float area_iss =B.area();
    cout << "area_iss " << area_iss << endl;
    return 0;
} 


