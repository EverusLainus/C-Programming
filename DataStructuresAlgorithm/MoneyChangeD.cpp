#include <iostream>
using namespace std;

int get_change(int m) {
//   cout<<"the money is "<< m<< endl;
  int MinNumCount[m+1]; //array of min count of each number from 0 to m.
  
  int denomination[3];//denominaton from question 1,3,4.
  denomination[0]=1; 
  denomination[1]=3;
  denomination[2]=4;
  
  MinNumCount[0]=0;//min count of 0 is o
  int NumCoins=0;

  for(int i=1; i<=m; i++){
    MinNumCount[i]=1000;//assigned to max possible value
    
    for(int j=0; j<3; j++){ //for each denomination j
        
        if(i>= denomination[j] ){ //if jth denomiation is >= the number
            int k=denomination[j];
            NumCoins = MinNumCount[i-k]+1;//(count of last number-k ) + 1.
            
            if(NumCoins < MinNumCount[i]){
               MinNumCount[i]= NumCoins; 
            }   
        }
    }
  }
  return MinNumCount[m];//return mth number
}

int main() {
  int m;
    cin >> m;
    cout << get_change(m) << '\n';
}