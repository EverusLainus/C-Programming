#include <iostream>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return current % 10;
}

int get_fibonacci_last_digit_fast(long long int n){
    if(n<=1){
        return n;
    }
    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = (previous%10);
        previous = (current%10);
        current = tmp_previous + current;
    }
    return current % 10;

}

/*
void test_solution() {
    assert(get_fibonacci_last_digit_naive(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 20; ++n){
       // cout << "come" << endl;
        assert(get_fibonacci_last_digit_naive(n) == get_fibonacci_last_digit_fast(n));
    }
}
*/

int main() {
    long long int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int d = get_fibonacci_last_digit_fast(n);
    //std::cout << c << '\n';
    std::cout << d << '\n';
    //test_solution();
    }
