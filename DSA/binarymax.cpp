#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int findMaxLength(vector<int>& nums) {
        int start =0;
        int count[2];
        int maxLen =0;
        for(int end =0; end <nums.size(); end++){
            cout <<"start: "<<start<< " end: "<<end<<endl;
            count[nums[end]]++;
            start = end;
            while(count[0] != count[1] && start>=0){
                cout <<"  while with start: "<<start<< " end: "<<end<<endl;
                count[nums[start]]--;
                start--;
            }
            if(count[0] == count[1]){
                maxLen = max(end+1-start, maxLen);
            }
        }
    return maxLen;
}

int main(){
    vector <int> num = { 0,1,0,1};
    int res = findMaxLength(num);
    cout<<"max length : "<<maxLen<<endl;
}