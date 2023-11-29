#include <iostream>
#include <unordered_map>

int main() {
    // Declare an unordered_map with int keys and string values
    std::unordered_map<int, std::string> myMap;

    // Insert key-value pairs into the hash map
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";


    // Check if a key exists in the hash map
    int keyToFind;
    std::cin >>keyToFind;
    if (myMap.find(keyToFind) != myMap.end()) {
        std::cout << "Key " << keyToFind << " found. Value: " << myMap[keyToFind] << std::endl;
    } else {
        std::cout << "Key " << keyToFind << " not found." << std::endl;
    }
    return 0;
}
