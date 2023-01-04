#include <iostream>
using namespace std;

//given naive algorithm
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }
    return sum % 10;
}
//get pisano period
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
        if(previous == 0 && current == 1){
           index = i+1;
        }
    }
//cout<< " pisano index is " << index << endl;
return index;
}
//find n mod m in the first period
long long int get_fibonacci_huge_fast(long long int  n,  long long int m) {
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
//find last dijit of sum of squares of first n fibonacci number using
//sum of square of first n fibonacci numbers is [F(n-1)+F(n-2)] * [F(n-1)+F(n)]
//take m =10 to find last digit.
long long fibonacci_sum_squares_fast(long long n){
    if (n <= 1)
        return n;
    return ((get_fibonacci_huge_fast(n-1,10)+get_fibonacci_huge_fast(n-2,10)) * (get_fibonacci_huge_fast(n-1,10)+get_fibonacci_huge_fast(n,10)))%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
//std::cout << fibonacci_sum_squares_naive(n)<< endl;
    std::cout << fibonacci_sum_squares_fast(n);
    return 0;
}