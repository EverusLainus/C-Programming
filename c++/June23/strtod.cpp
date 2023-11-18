//illustrate the use of strtod function

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


void string_to_double(const std::string &s, double &res) {
    char *end_ptr = NULL;
    res = strtod(s.c_str(), &end_ptr);
    cout <<"end string: " <<end_ptr<<endl;
}

int main(){
    string s = "3.4607 only";
    cout <<"input string: "<<s<<endl;
    double res = 0;
    string_to_double(s, res);
    cout <<"resultent double: " <<res<<endl;   
    return 0;
}