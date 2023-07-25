//check the control flow of the "throw" keyword
#include <iostream>
using namespace std;

class Class{
    public:
//constructor;
    Class(){
        cout<<"object constructed"<<endl;
    }
    void SecretCode(){
        cout<<"Á vaillant coeur rien d'impossible"<<endl;
    }
//destructor
    ~Class(){
        cout<<"object destructed"<<endl;
    }
};

void intermediate(int i){
    if(i==0){
        throw string("i will win every single game");
    }
    Class object;
    object.SecretCode();
    if(i==1){
        throw string("Bet you cannot guess Who is by my side");
    }  
}

int main(){
    int j=0;
    while(j<2){
        cout <<"******"<<endl;
        try{
            intermediate(j);
        }
        catch(string &lucky){
            cout<<lucky<<endl;
        }
        j++;
    }
    
    return 0;
}


/*
output:
******
i will win every single game
******
object constructed
Á vaillant coeur rien d'impossible
object destructed
Bet you cannot guess Who is by my side


observe:
when an a control flow reaches a throw keyword in a function
it quits all the processes in the function 
then goes in search of the catch statatement 
and the continuous from the next instruction 
where the catch fuction is 

*/