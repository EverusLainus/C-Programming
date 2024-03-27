#include <algorithm>
#include <vector>
#include <iostream>
#include<string>
using namespace std;

    int whileWhile(string s) {
        int n = s.size();
        int start = 0;
        int end =0;
        while(  end<n){
         
            while( start < end){
                cout << "into inner while"<<endl;
                //cout << string(s.begin()+start, s.begin()+end+1)<<endl;
                start++;
                
            } 
            cout << string(s.begin()+start, s.begin()+end+1)<<endl;         
            end++;
        }
        return 1;
    }

int main(){
   // vector <int> num = {2,5,9,6,9,3,8,9,7,1};
    vector <int> num = {3,8,9,7,1};
    int res = whileWhile("012345678");
    //cout<<"repeated element : "<<res<<endl;
}