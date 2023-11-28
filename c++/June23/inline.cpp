//inline functions
/*
an inline function is a function that, at the compiler's discretion, 
is expanded in place at each point in the code where it is called, 
rather than being executed through a regular function call. 

//speeds up program
*/

#include <iostream>
using namespace std;

static uint64_t get_monotonic_usec() {
    timespec tv = {0, 0};
    clock_gettime(CLOCK_MONOTONIC, &tv);
    return uint64_t(tv.tv_sec) * 1000000 + tv.tv_nsec / 1000;
}

// Declaration of an inline function
inline int add(int a, int b) {
    return a + b;
}

int add_normal(int a, int b) {
    return a + b;
}

int main() {
    uint64_t start_time = get_monotonic_usec();
    //cout << "start time "<<start_time<<endl;
    int result = add(3, 4);  // The function call is replaced with the actual code
    uint64_t after_inline_func = get_monotonic_usec();
    cout <<"time just after calling inline function "<<after_inline_func<<endl;
    std::cout << "Result: " << result << std::endl;
    std::cout << "time taken after inline function: " <<after_inline_func - start_time << std::endl;

    int result1 = add_normal(3, 4); 
    uint64_t after_normal_func = get_monotonic_usec();
    cout <<"time just after calling normal function "<<after_normal_func<<endl;
    std::cout << "Result: " << result1 << std::endl;
    std::cout << "time taken after normal function: " <<after_normal_func -after_inline_func<< std::endl;

    return 0;
}
