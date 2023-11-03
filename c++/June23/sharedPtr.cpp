#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> p1 = std::make_shared<int>(42);
    std::shared_ptr<int> p2 = p1;

//p1.use_count() to find no of times p1 is used
    std::cout << "p1 use count: " << p1.use_count() << std::endl; // Prints 2

//to delete ptr p1 
    p1.reset();  // Release ownership from p1

    std::cout << "p1 use count after reset: " << p1.use_count() << std::endl; // Prints 0, object is deleted

//to delete ptr p2
    p2.reset();

    std::cout << "p2 use count after reset: " << p2.use_count() << std::endl; // Prints 0, object is deleted

    return 0;  // p2 goes out of scope, the object is deleted
}