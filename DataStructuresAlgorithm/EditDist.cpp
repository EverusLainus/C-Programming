#include <iostream>
#include <string>
using namespace std;
using std::string;

//minimum function
int Min(int a,int b, int c){
  if(a>b){
    if(b<c){
      return b;
    }
    else{
      return c;
    }
  }
  else{
    if(a<c){
      return a;
    }
    else{
      return c;
    }
  }
}

int edit_distance( string str1, string str2, int n, int m) {
  int v[n+1][m+1];
  for(int i=0;i<(n+1);i++){
    for(int j=0; j<(m+1); j++){
      if(i==0){
        v[i][j]=j;
      }
      else if(j==0){
        v[i][j]=i;
      }
      else if(str1[i-1]== str2[j-1]){
        v[i][j]=v[i-1][j-1];
      }
      else{
        v[i][j]= 1+Min(v[i][j-1], // Insert
                v[i-1][j], // Remove
               v[i-1][j-1] // Replace
              );
      }
    }
  }
  return v[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2, str1.length(), str2.length()) << std::endl;
  return 0;
}
