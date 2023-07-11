// static fuction compontents

#include <iostream>
using namespace std;

class Class{
    static int counter;
    public:
    Class(){
        ++counter;
    }
    static void How_many(){
        cout <<counter<<" instances"<<endl;
    }
    ~Class(){
        if(counter ==0){
            cout <<"bye bye "<<endl;
        }
        else{
            --counter;
        }       
    }  
};
int Class::counter=0;

int main(){
    Class a;

//ways to invoke static function
    a.How_many();
    Class::How_many();

    return 0;
}