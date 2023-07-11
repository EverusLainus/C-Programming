// static field

#include <iostream>
using namespace std;

class Class{
    public:
    int non_static;
//static comes before datatype
    static int Static; 

    void print(){
        cout<<"the static"<<(++Static)<<endl;
        cout<<"the non_static"<<(non_static+1)<<endl;
    }
};
//dont use "static int" here. only int works 
int Class::Static=1;

int main(){
    Class c1;
    c1.non_static=10;
    c1.Static+=3;
    c1.print();

    Class c2;
    c2.non_static=20;
    c2.Static+=5;

//can also be assigned using ::
//works for public static variable
    Class::Static=79;
    c2.print();
    return 0;

}