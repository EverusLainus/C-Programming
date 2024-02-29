#include <iostream>
#include <map>
#include <vector>
using namespace std;

    bool containsDuplicate(vector<int>& nums) {
        int flag = true;
        map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                cout << "false at "<< nums[i]<<endl;
                flag = false;
                return false;
            }else{
                m[nums[i]] =1;
            }
        }
        if(flag) cout <<"true"<<endl;
        else cout << "false"<<endl;
        return true;
    }

    int main(){
        vector <int> nums;
        for (int i = 1; i <= 5; i++) 
        nums.push_back(i); 

        //nums.push_back(1); 
        containsDuplicate(nums);
        return 1;
    }