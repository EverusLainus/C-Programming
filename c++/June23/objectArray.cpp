//create an array of objects

#include <iostream>
#include <vector>
using namespace std;

class Array{
    public:
    string Name;
    int score;

    void put(int idx, string str, int a){
        Array::Name=str;
        Array::score=a;
    }

    
};

int main(){
     vector <Array *> ptrAry={new Array, new Array};
     return 0;
}