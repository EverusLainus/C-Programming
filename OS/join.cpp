
//use -std=c++14 
//use commands from this_thread and join.
#include <iostream>
#include <thread>

//using namespace std;

void func(){
    using namespace std::literals::chrono_literals;
    std::cout << "i am a thread. My ID is "<<std::this_thread::get_id()<<std::endl;
    std::this_thread::sleep_for(6s);
}

int main(){
    std::thread T1(func);
    std::cin.get();
    T1.join();
    std::cout << "i am a thread. My ID is "<<std::this_thread::get_id()<<". We are done."<<std::endl;
    return 0;
}