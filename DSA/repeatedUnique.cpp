#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

    int findDuplicate(vector<int>& a) {
        int n = a.size();
        int res = 0;
        for(int i=0; i<n; i++){
            a[i]--;
        }
        for(int i=0; i<n; i++){
            cout <<"compare "<<a[i]<<" "<<i<<endl;
            if(a[i] != i){           
                //sway i and a[i]-1
                
                int temp = a[a[i]];
                cout << "swap "<< a[i]<<" "<<a[a[i]]<<" temp: "<<temp<<" i"<<i<< endl;
                a[a[i]] = a[i];
                a[i] = temp;
                //if(a[i] == a[a[i]]) return a[i]+1;
            }
            for(int x: a){
                cout <<x<<" ";
            }
            cout<<endl;
        }
        for(int i=0; i<n; i++){
            cout << a[i]<<" ";
            if(a[i] != i ){
                res = a[i]+1;
                break;
            }
        }
        return res;
    }
    int main(){
   // vector <int> num = {2,5,9,6,9,3,8,9,7,1};
     vector <int> num = {3,8,9,7,1};
    int res = findDuplicate(num);
    cout<<"repeated element : "<<res<<endl;
}