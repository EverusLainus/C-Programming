//sort in assending order using cpp library

#include <iostream>
#include <algorithm>
#include <functional> //for grater<int>
using namespace std;

/*
greater<int>(): greater<int> is a binary function object (a functor) 
that represents the greater-than operator for integers. 
When used as the third argument in the std::sort function, 
it specifies that you want to sort the elements in descending order, 
as it reverses the default sorting order (ascending).
*/
int main(){
    vector <int> values = {3, 4, 1, 4, 5};
    //third arg can be struct or nothing or lambda
    sort(values.begin(), values.end(), greater<int>());

    for(int value : values){
        cout <<value<<endl;
    }
    return 1;
}