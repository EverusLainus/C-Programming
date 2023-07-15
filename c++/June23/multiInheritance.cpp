// a simple example for multiple inheretance

#include <iostream>
using namespace std;

class Super1{
    protected:
    int value;
    public:   
    void put(int val){
        Super1::value=val;
    }
    int get(){
        return value;
    }
};

class Super2{
    protected:
    int storage;
    public:
    void add(int val){
        Super2::storage=val;
    }
    int takeout(){
        return storage;
    }
};

class Sub : public Super1, public Super2{
    public:
    void print(){
        cout<<"value is "<< Sub::value;
        cout<<"\n storage is "<<Sub::storage;
    }

};

int main(){
    Sub my_class;
    my_class.add(2);
    my_class.put(11);
    my_class.print();
    return 0;
}