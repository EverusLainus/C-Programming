#include <iostream>
using namespace std;

//find pisano period
long long int Pisano(long long m){
    long long previous =0;
    long long current =1;
    long long index=0;
    for (int i=0 ; i< m*m; i++){
        long long temp =0;
        temp =current;
        current = (previous +current)%m;
        previous =temp;
        if (previous == 0 && current == 1){
            index =i+1;
        }
    }
    //cout << "pisano is" << index<< endl;
    return index;
}

//given naive algorithm
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = 0;
        tmp_previous = current;
        current = (previous + current)%10;
        previous = tmp_previous;
        sum += (current);
    }
    return sum % 10;
}

//use pisano period of 10 to shorten the length of n and use mod 10 arithmetic
long long fib_sum_fast(long long n)
{
    long long period=Pisano(10);
    n=n % period;
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = 0;
        tmp_previous = current;
        current = (previous + current)%10;
        previous = tmp_previous;
        sum += (current);
    }
    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout<< "naive"<< fibonacci_sum_naive(n)<< endl;
    std::cout  << fib_sum_fast(n)<< endl;
    return 0;
}