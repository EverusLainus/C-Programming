#include <iostream>
#include <array>

void circularTour(int n, int g[], int c[]){
    int start =0;
    int value =0;
    int remain =0;
    for(int i=0; i < n; i++){
        value+=( g[i]-c[i]);
        if(value <0){
            start = i+1;
            remain += value;
            value =0;
        }
    }
    if(remain + value >=0){
        std::cout <<start<<std::endl;
    }else{
        std::cout <<-1<<std::endl;
    }
    
}

int main(){
    int gas[] = { 1, 2, 3 , 4, 5};
    int cost[] = { 3, 4, 5, 1, 2};
    int n = 5;
    circularTour(n, gas, cost);
    return 0;
}