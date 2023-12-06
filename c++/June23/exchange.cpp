//exchange function is part of the C++14 standard
// This can be useful when you want to capture the previous state of a variable.

#include <iostream>
#include <utility>

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Before exchange: a = " << a << ", b = " << b << std::endl;

    // Using std::exchange to swap values
    std::exchange(a, b);

    std::cout << "after exchange: a = " << a << ", b = " << b << std::endl;

    // Using std::exchange to update a value
    int newValue = 30;
    int oldValue = std::exchange(a, newValue);
    //oldValue has the value of a before modification

    std::cout << "After updating: a = " << a << ", oldValue = " << oldValue << std::endl;

    return 0;
}
