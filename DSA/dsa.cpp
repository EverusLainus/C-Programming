#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    int left[n];
    int right[n];
    int product = 1;
    for(int i=0;i<nums.size(); i++){
        product *= nums[i]; 
        left[i] = product;
    }
    product =1;
    for(int i = n-1 ;i >= 0 ; i--){
        product *= nums[i]; 
        right[i] = product;
    }
    for(int x: left){
        cout << x<<" ";
    }
    cout <<endl;
    for(int x: right){
        cout << x<<" ";
    }
    cout <<endl;

     vector<int> answer;
     answer.insert(answer.end(), right[1]);
     for(int i=1;i<n-1; i++){
         answer.insert(answer.end(), left[i-1] * right[i+1]);
     }
     answer.insert(answer.end(), left[n-2]);
     return answer;
}
int main(){

    
    vector <int> num = { 1,2,3,4};
    vector<int> result = productExceptSelf( num);
    for(int x: result){
        cout << x<<endl;
    }

}