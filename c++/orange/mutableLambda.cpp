#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
//withot constants on for_each arguments it shows error
void for_each(const vector<int> &values, const function<void(int)>& func){
    for(int value: values){
        func(value);
    }
}

int main(){
    vector <int> values = {1, 5, 6, 3, 2, 2};
    int num = sizeof values;
    //mutable keyword will let us modify the variables
    auto lambda = [num](int value) mutable {num =5;cout<< "value: "<<value<<" .In vector of size "<< num<<endl;};
    for_each(values, lambda);
    return 0;
}

