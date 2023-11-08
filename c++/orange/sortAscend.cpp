//sort in assending order using cpp library

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    vector <int> values = {3, 4, 1, 4, 5};
    sort(values.begin(), values.end());

    for(int value : values){
        cout <<value<<endl;
    }
    return 1;
}