#include <iostream>
#include <string>
#include <map>

/**
 * @brief using hash map to store the character and corresponding frequency of first string;
 *  for every character in string two decrement the frequency;
 *  characters in both string should have same frequency;
 * @param string1 - string one 
 * @param string2 - string two
 * @return true - if they are anagrams
 * @return false - if they are not anagrams
 */
bool isAnagram(std::string string1, std::string string2){

    //if the length of two strings are not same return false
    if(string1.length() != string2.length()){
        return false;
    }

    std::map <char, int> m;

    //through the characters of s1 and increment its value;
    for(int i=0; i<string1.length(); i++){
        m[string1[i]] += 1; 
    }

    /* *
    keys of map are distinct characters of the string.
    */
    //std::cout << m.size();

    //decrease the frequency of each key
    for(int i=0; i<string2.length(); i++){
       if(m.find(string2[i]) != m.end()){
            m[string2[i]]--;
       }
    }
    //both the string should have same frequency for every character
    for(auto items: m){
        if(items.second != 0){
            return false;
        }
    }
    return true;
}

int main(){
    std::string string1 = "silent";
    std::string string2 = "listen";
    if(isAnagram(string1, string2)){
        std::cout << "Anagram";
    }else{
        std::cout << "not an Anagram"; 
    }
}
