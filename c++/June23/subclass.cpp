#include <iostream>
using namespace std;

class account{
 private:
 string account_holder ;
 int account_no;

 public:
 //constructor to initialise private variables
 account(){
    this->account_no=1;
 }
 string set_account_holder(string str){
    this->account_holder=str;
        return this->account::account_holder;
   }
 
 string get_account_holder(){
        return this->account::account_holder;
   }
 
};
//to access the methods of "account" from the object of subclass
//"expand_account" we need to add public before "account "
//while forming subclass.
class expand_account : public account{
    int total_amount;

    public:
    expand_account(){
        this-> total_amount=0;
    }

    string withdraw(int amount);
    void deposit(int amount){
      expand_account::total_amount += amount;
    }

    int get_total_amount(){
        return expand_account::total_amount;
    }  
};

string expand_account::withdraw(int amount){
    if(amount <= total_amount){
        expand_account::total_amount -= amount;
    }
    else{
        return "not enough cash";
    } 
    return "done";
}

int main(){
    expand_account One;
    One.set_account_holder("Alen");
    cout <<"account name "<< One.get_account_holder() <<endl;
    One.deposit(100);
    One.withdraw(75);
    cout<< "balance is "<<One.get_total_amount()<<endl;
    return 0;   
}