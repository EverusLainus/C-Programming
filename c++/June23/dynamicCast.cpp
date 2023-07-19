// experiment with dynamic cast, pass by 
#include <iostream>
using namespace std;

class Pet {
protected:
    string name;
public:
    Pet(string name) : name(name) {}
    virtual void make_sound(){ 
        cout << name << " is silent :(" << endl; 
    }
};

class Dog : public Pet {
public:
    Dog(string name) : Pet(name) {}
    void make_sound(){ 
        cout << name << " says: Woof!" << endl; 
    }
};

class GermanShepherd : public Dog {
public:
    GermanShepherd(string name) : Dog(name) {}
    void make_sound(){
        cout << name << " says: Wuff!" << endl; 
    }
    void laufen(){ 
        cout << name << " runs (shepherd)!" << endl; 
    }
};

void play_with_pet(Pet *pet){
    pet -> make_sound();
    GermanShepherd *shepherd = dynamic_cast<GermanShepherd *>(pet);
    if(shepherd != nullptr)
        shepherd -> laufen();
}

int main(){
    Pet *pet                 = new Pet("creature");
    Dog *dog                 = new Dog("Dog");
    GermanShepherd *shepherd = new GermanShepherd("Hund");
    
    play_with_pet(pet);
    play_with_pet(dog);
    play_with_pet(shepherd);
}

/*
note:
#   remome "virtual" from Pet.make_sount
    =>error:'Pet' is not polymorphic
    # even using try and catch int the statements wont help

#   in play_with_pet function: repace dynamic with static
    remove "virtual" from Pet.make_sound or leve it there
    => Pet, Dog and GermanSheperd are change into GermanShepard
*/