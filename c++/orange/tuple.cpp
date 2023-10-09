//try tuple

#include <iostream>
#include <utility>
#include <functional>

using namespace std;

//tuple is used to return values of multiple types
tuple<string, int> multiple_return(){
    string str = "Angel";
    int num = 11;
    return make_pair(str, num);
}

int main(){
    //tuple <string, int> res = multiple_return();
    string a;
    int b;

    //The work of tie() is to unpack the tuple values into separate variables
    tie (a, b) = multiple_return();

    //Returns a pointer to an array that contains a null-terminated sequence of characters 
    //a wont work

    printf("the return is %s, %d\n", a.c_str(), b);
    return 0;
}