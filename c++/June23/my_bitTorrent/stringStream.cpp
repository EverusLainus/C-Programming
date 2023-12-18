#include <iostream>
#include <sstream>

int main() {
    // Create a std::stringstream object
    std::stringstream buffer;
    const uint32_t messageLength = 12;
    char * message_len = (char *)&messageLength;
    std::string string_length;

    // Insert data into the stringstream
    for(int i=0; i<4; i++){
        std::cout <<(char)message_len[3-i]<<" ";
        string_length.push_back((char) message_len[3-i]);
    }
    buffer << string_length;
    buffer << "Hello, ";
    buffer << 123;
    buffer << " world!";

    // Retrieve the contents of the stringstream as a string
    std::string result = buffer.str();

    // Output the result
    std::cout << result << std::endl;

    return 0;
}
