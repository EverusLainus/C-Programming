//subclass can access the public components of the super class
//but super class cannot access and components of the sub class

//we use pointers to declare objects

#include <iostream>
using namespace std;

class Pet{
    protected:
    string str;
    public:
    void make_sound(){
        cout <<str<<" says : shh! shh!"<<endl;
    }
    Pet(string n){
        Pet::str=n;
    }
    void run(){
        cout<<"hey i am running "<<endl;
    }
};

class Cat : public Pet{
    public:
    Cat(string n) :Pet(n){
    }
    void make_sound(){
        cout <<"cat says :meaw meaw"<<endl;
    }
    void present(){
        cout<<"hello i'm Cat"<<endl;
    }
};

class Dog : public Pet{
    public:
    Dog(string n) :Pet(n){
    }
    void make_sound(){
        cout <<"dog says :bow bow"<<endl;
    }
    void present(){
        cout<<"hello i'm Dog"<<endl;
    }
};

int main(){
//this is also a right way to initialise
    Pet *a_pet1;
    a_pet1->run();

//  we cannot use new keyword to assign a Pet to Cat or Dog
//  Cat *a_cat=new Pet("tom");

//we can assign a new cat or dog to pet
    Pet *a_pet=new Cat("tom");

//yet cannot access cat's components from Pet.
    a_pet->run(); a_pet->make_sound();
//    a_pet->present();

//there is a way out!
//use static_cast
//a_pet is temporarly converted to Dog *.
    static_cast<Dog *>(a_pet)->present();

//observe that Cat overrides the make_sound() function
//defined by Pet.
    return 0;
}