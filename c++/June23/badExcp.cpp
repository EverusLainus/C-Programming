// the bad_exception - subclass of exception class
//not use since c++17
//compiles in c++11, c++14 using 
//-std=c++14, -std=c++11 flag

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

void excp(){
    cout <<"gotcha, passing it over"<<endl;
     throw;
}

//without throw in head the code didnt work
float Pi() throw(int, bad_exception) {
    cout <<"i am inside Pi!"<<endl;
    throw 3.14;
}

int main(){
    set_unexpected(excp);
    try{
        cout<<"let's try Pi"<< endl;
        Pi();
    }
    catch(int i){
        cout <<"got int"<<endl;
    }
    catch(bad_exception bad){
        cout<<"oh! it's gross"<<endl;
    }
    return 0;
}

/*
let's try Pi
i am inside Pi!
libc++abi: terminating due t
*/