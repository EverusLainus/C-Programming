
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:


    long long countSubstrings(string s, char c) {
        long long count =0;
        long long factorial =0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == c){
                count++;
                factorial = factorial + count;
            }
        }
        return factorial;
    }

    
};