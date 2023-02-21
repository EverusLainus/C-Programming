#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int lcs3(vector<int> a, vector<int> b, vector<int> c, int r, int s, int t) {
    int v[r+1][s+1][t+1];
    
    //initialise every cell as 0
    for(int i=0; i<r+1; i++){
        for(int j=0; j<s+1; j++){
            for(int k=0; k<t+1; k++){
                v[i][j][k]=0;
            }
        }
    }
    
    //for i,j,k>0
    for(int i=1; i<r+1; i++){
        for(int j=1; j<s+1; j++){
            for(int k=1; k<t+1; k++){
                //if a[i-1]==b[j-1]==c[k-1]
                if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
                    v[i][j][k]=v[i-1][j-1][k-1]+1;//add 1
                }
                else{
                    //find max of previous sequence leaving any one index
                    v[i][j][k]=max(max(v[i-1][j][k], v[i][j-1][k]), v[i][j][k-1]);
                }
            }
        }
    }   
  return v[r][s][t];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c, an,bn,cn) << std::endl;
}

/*
testcase:
3
1 2 3 
3 
2 1 3 
3 
1 3 5

5
8 3 2 1 7
7
8 2 1 3 8 10 7 
6
6 8 3 1 4 7
*/
