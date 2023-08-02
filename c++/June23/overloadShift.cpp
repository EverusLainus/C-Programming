//overload >> operator of vectors
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
    vector_class operator>> (int arg){
    //'*' inside is just multiplication
        vector_class res;
        //assign each vector index
            res.vector1=this->vector1;
            res.vector2=this->vector2;

            //>> on each vector index
            res.vector1 >>= arg;
            res.vector2 >>= arg;
        return res;
    }

};

int main(){
    vector_class v1(15,7);
    v1 = v1>>3;
    cout << "( "<<v1.vector1<<" , "<<v1.vector2<<" )" <<endl;//prints 14
    return 0;
}