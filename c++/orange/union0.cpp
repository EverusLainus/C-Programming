//union 
/*
address same memory with different names
*/

#include <iostream>
using namespace std;

struct Union{
    union{
        int x;
        float y;
        double z;
    };
};

int main(){
    Union u;
    u.x = 2;
    cout << u.x << ", "<< u.y << ", "<<u.z <<endl;
    
    //all members points to same address
    cout << "address of u.x , u.y, u.z is "<<&u.x<< ", "<<&u.y<< ", "<<&u.z<<endl;
    return 0;
}