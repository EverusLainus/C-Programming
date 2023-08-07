//overload != operator for vectors
#include <iostream>
#include <vector>
using namespace std;

class vector_class{
    public:
    int vector1;
    int vector2;
    vector_class(int a=0, int b=0 ){
        vector1=a;
        vector2=b;
    }

    //can be overloaded globally
    bool operator <= (vector_class v){

            //== on each vector index
            if((this->vector1 <=v.vector1) && (this->vector2 <=v.vector2)) {
                return true;

            }
        return false;
    }

};

int main(){
    vector_class v1(1,7);
    vector_class v2(15,7);
    bool result = (v1<=v2);
    cout << result;
    return 0;
}