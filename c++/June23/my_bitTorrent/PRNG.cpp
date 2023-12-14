#include <random>
#include <iostream>

int main(){

    std::string peerId = "-UT2023-"; 
    std::random_device rd; //random fixed seed
    std::cout << "Random Value: " << rd() << std::endl;

    /*This line creates an instance of the Mersenne Twister random number generator (std::mt19937) and s
    eeds it with a value obtained from the std::random_device rd. */
    std::mt19937 mt_gen(rd());
    std::cout << "Random Value by Mersenne Twister random number generator : " << mt_gen() << std::endl; 

    /*
    std::uniform_int_distribution<>, which generates integers uniformly distributed within a specified range.*/
    std::uniform_int_distribution<> uni_int_dist(1,9);
    
    // Append a random number to peerId
    for(int i=0;i<12;++i){
        peerId += std::to_string(uni_int_dist(mt_gen));
    }

    std::cout << "Final peerId: " << peerId << std::endl;
    return 0;
}
