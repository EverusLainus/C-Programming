//program to illustrate remove keyword
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    // Create a string with unnessary character h
    std::string str = "Hello,hhhhWorldhhh";

    // Use std::remove to remove h
    str.erase(std::remove(str.begin(), str.end(), 'h'), str.end());

    // Output the modified string
    std::cout << "Modified String: " << str << std::endl;

    return 0;
}
