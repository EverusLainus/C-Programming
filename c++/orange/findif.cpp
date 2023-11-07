//to find something inside a iterator use findif

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> values = {1, 2, 3, 4};
    auto it = find_if(values.begin(), values.end(),[](int value){ return value >2;} );
    //it is the pointer to a value
    cout <<"first value in the vector with value > 2 : "<< *it<<endl;
    return 1;
}
