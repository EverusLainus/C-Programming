// test virtual keyword

#include <iostream>
using namespace std;

class Pet{
    private:
    string str;
    public:
    Pet(string n){
        Pet::str=n;
    }
    void pet_run(){
        cout<<"pet is running"<<endl;
    }
    //influenced by subclass
    virtual void make_sound(){
        cout<< "Pet says: shh! shh!"<<endl;
    }
};

class Cat : public Pet{
    public:
    Cat(string n) : Pet(n) {
    }
     void make_sound(){
        cout<< "cat says: meaw! meaw!"<<endl;
    }
};

class Dog : public Pet{
    public:
    Dog(string n) : Pet(n) {
    }
    void dog_run(){
        cout<<"dog is running"<<endl;
    }
     void make_sound(){
        cout<< "dog says: wow! wow!"<<endl;
    }
};

int main(){
    Pet *pet1, *pet2;
    Cat *cat1;
    Dog *dog1;

    pet1=cat1=new Cat("kitty");
    pet2=dog1=new Dog("doggy");

    pet1->make_sound();
    cat1->make_sound();
    //virtual reworte the make_sound in pet1;
    static_cast<Cat *> (pet1)->make_sound();

    pet2->make_sound();
    dog1->make_sound();
    static_cast<Dog *> (pet2)->make_sound();
    return 0;
}

/*
output:
cat says: meaw! meaw!
cat says: meaw! meaw!
cat says: meaw! meaw!
dog says: wow! wow!
dog says: wow! wow!
dog says: wow! wow!
*/