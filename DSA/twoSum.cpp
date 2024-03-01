#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


    vector<int> twoSum(vector<int>& nums, int target){
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int l= 0;
        int r= nums.size()-1;
        vector <int> res;
        while(l<r){
            cout <<"["<<l<<","<<r<<"]"<<" targer: "<< target<<endl;
            if(nums[r]+nums[l] > target){
               r--; 
            } else if(nums[r]+nums[l] < target){
               l++; 
            }else if((nums[r]+nums[l]) ==  target){
               cout <<"["<<r<<","<<l<<"]"<<endl;
               res.push_back(r);
               res.push_back(l);
               break;
            }
        }
        return res;
    }


int main(){
    vector <int> num = { 3, 2, 4};
    int k = 6;
    vector<int> result = twoSum(num, k);
    for(int x: result){
        cout << x<<endl;
    }

}