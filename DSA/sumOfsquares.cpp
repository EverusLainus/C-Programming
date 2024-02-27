#include<iostream>
#include <math.h>
#include <map>

void sumOfSquare(long k){
    bool flag = false;
    std::map<int, int> Map;
    for(int i = 1; i < sqrt(k); i++){
        Map[i*i] =1;
        //System.out.println(k-(i*i));
        int  l = (int) k-(i*i);
        if(Map.find(Map[i]) != Map.end()){
            flag = true;
            break;
        }
    }
    std::cout << flag <<std::endl;
}



int main(){
    long k = 25;
    sumOfSquare(k);
}