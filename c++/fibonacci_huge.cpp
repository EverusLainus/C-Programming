#include <iostream>
using namespace std;

//fibonacci sequnce mod m has a period called Pisano period. 
//for every fibonacci number n mod m a period starts with 0, 1,..
// length of the period is at most m*m 
long long int getPisano(long long int m){
    long long int previous =0;
    long long int current =1;
    long long int index =0;
//from 0 till m*m find period of F_n mod m     
    for (int i=0 ; i<m*m ;i++){
        long long int temp =0;
        temp = current;
        current = (previous +current)% m;
        previous = temp;
        if(previous ==0 && current ==1){
           index = i+1;
        }
    }
//cout<< " pisano index is " << index << endl;
return index;
}

long long int get_fibonacci_huge_naive(long long int  n,  long long int m) {
// find pisano for m and take n mod m    
    long long int pisano = getPisano(m);
    n = n % pisano;
    if (n <= 1)
        return n;

    long long int  previous = 0;
    long long int current  = 1;

    for (long long int  i = 0; i < n - 1; ++i) {
        //std::cout << "i is "<< i <<" " <<'\n';
        //std::cout << current << '\n';
        long long int tmp_previous = previous %m;
        previous = current % m;
        current = tmp_previous + previous;
    }
    //std::cout << (current % m) << '\n';

    return current % m;
}

int main() {
    long long int n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
