#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum My{
    START =6,
    MIDDLE = 1,
    END =2
};


int main(){
    string out;
    //out_str(out);
    My my = START;
    out += std::to_string(my);
    std::cout << out << std::endl;
    return 0;
}