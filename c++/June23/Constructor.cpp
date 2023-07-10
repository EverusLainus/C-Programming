#include <iostream>
using namespace std;

class Class {
public:
    Class() 
    { 
        this -> value = -1; 
    }
    void set_val(int value) 
    { 
        this -> value = value; 
    }
    int get_val() 
    { 
        return value; 
    }
private:
    int value;
};

int main(){
    Class object;
 //   ensure that the constructor initialises the value field
    cout << object.get_val() << endl;
    return 0;

}