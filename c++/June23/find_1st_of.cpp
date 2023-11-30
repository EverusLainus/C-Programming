#include <iostream>
#include <string>

int main() {
    std::string text = "Hello, World!";
    size_t position = text.find_first_of("aeiou");
    if (position != std::string::npos) {
        std::cout << "Found vowel at position: " << position << std::endl;
    } else {
        std::cout << "No vowel found." << std::endl;
    }
    return 0;
}
