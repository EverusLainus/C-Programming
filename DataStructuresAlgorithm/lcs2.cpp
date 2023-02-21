#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int lcs2(vector<int> a, vector<int> b, int n, int m) {

  int v[n+1][m+1];
  for(int i=0;i<(n+1);i++){
    for(int j=0; j<(m+1); j++){
      if(i==0 || j==0){
        v[i][j]=0;
      }
      else if(a[n-i]== b[m-j]){
        v[i][j]=1+v[i-1][j-1];
      }
      else{
        int a=v[i][j-1];
        int b= v[i-1][j];
        int c=v[i-1][j-1];
        v[i][j]= max(a, // Insert
               max(b,c) // Replace
              );
      }
    }
  }
  return v[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  std::cout << lcs2(a, b, a.size(), b.size()) << std::endl;
}

/*
3
2 7 5
2
2 5

1
7
4
1 2 3 4

4
2 7 8 3
4
5 2 8 7

3
3 4 8
3
8 7 3
*/