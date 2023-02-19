#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int main() {
  int n;
  std::cin >> n;//get a number
  int k=n;
  vector <int> V(n+1);

  for(int i =0; i< V.size()-1; i++){
    V[i]=0;//initialize every index to 0
  }
  V[1]=0;//1st idx is 1

  for(int i=1; i<n; i++){
    if(V[i+1]==0 || V[i+1]> V[i]+1){
      V[i+1]=V[i]+1;
    }
    if( i*2<=n && (V[i*2]==0 || V[i*2]> V[i]+1) ){
      V[i*2]=V[i]+1;
    }
    if(i*3<=n && (V[i*3]==0 ||V[i*3]> V[i]+1 ))
      V[i*3]=V[i]+1;
  }
  
  vector<int> ans;
    while(n > 1)
    {
        ans.push_back(n);
        if(V[n - 1] == V[n] - 1)
        {
            n = n-1;
        }
        
        else if(n%2 == 0 && V[n/2] == V[n] - 1)
        {
            n = n/2;
        }
        
        else if(n%3 == 0 && V[n/3] == V[n] - 1)
        {
            n = n/3;
        }
    }

    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout<< V[k]<<endl;
    for (size_t i = 0; i < ans.size(); ++i) {
      std::cout << ans[i] << " ";
    }
  return 0;
}

