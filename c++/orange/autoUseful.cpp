// an useful way to use auto

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> str_vector;
    str_vector.push_back("i");
    str_vector.push_back(" am");
    str_vector.push_back("great");

//if we wana print the vector

    for(vector<string>::iterator it = str_vector.begin(); it != str_vector.end(); it++){
        cout<<*it<<endl;
    }

//instead we could use auto to automatically set type of the it variable
    for(auto it = str_vector.begin(); it != str_vector.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}