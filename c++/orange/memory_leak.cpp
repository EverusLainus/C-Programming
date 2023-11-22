#include <iostream>
using namespace std;

class main_class{
    public:
    main_class(){
        cout << "main_class constructor\n";
    }
    virtual ~main_class(){
        cout << "main_class constructor\n";
    }
};

class sub_class : public main_class{
    public:
    sub_class(){
        cout << "sub_class destructor\n";
    }
    ~sub_class(){
        cout << "sub_class destructor\n";
    }
};

class sub_class_virtual : public main_class{
    public:
    sub_class_virtual(){
        cout << "sub_class_virtual destructor\n";
    }
    ~sub_class_virtual(){
        cout << "sub_class_virtual destructor\n";
    }
};

int main(){
    main_class *a= new main_class();
    delete a;
    cout <<"_______________\n";
    //here main class destructor is not called
    //add virtual to get destructor called
    main_class *b = new sub_class_virtual();
    delete b;
    cout <<"_______________\n";
    return 0;
}