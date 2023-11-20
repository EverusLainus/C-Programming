//illustrate the use of isnan function
#include <iostream>
#include <cmath>
using namespace std;
//works for int, double, long double

bool check_null(double &s) {

    return isnan(s);
}

int main(){
    double s = 0.89987;
    if(check_null(s)){
        cout <<"the value is null"<<endl;
    }else{
        cout <<"the value is not null"<<endl;
    }
    return 0;  
}