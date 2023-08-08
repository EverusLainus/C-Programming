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
    vector_class operator + (vector_class v){

            //== on each vector index
        this->vector1 += v.vector1;
        this->vector2 += v.vector2;

        return *this;
    }

};

int main(){
    vector_class v1(15,7);
    vector_class v2(15,7);
    vector_class result = v1+v2;
    cout << result.vector1 <<" "<<result.vector2;
    return 0;
}