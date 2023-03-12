#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits> //for llong_max and llong_min
using namespace std;

using std::vector;
using std::string;
using std::max; 
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int n = (length + 1) / 2;
  long long int M[n][n];
  long long int m[n][n];
  for(int i=0; i<n;i++){
    for(int j=0;j<n;j++){// initialize to 0
        M[i][j]=0;
        m[i][j]=0;
    }
  }

  long long int a,b,c,d;

  for(int i=0; i<n; i++){
    //The values on the main diagonal is just the number themselves
	  m[i][i] = std::stoll(exp.substr(2*i,1));
	  M[i][i] = std::stoll(exp.substr(2*i,1));
  }
  
  for(int s=0; s<(n-1);s++){
    for(int i=0; i<(n-s-1); i++){
      long long j=i+s+1;
      long long int Min =LLONG_MAX;
      long long int Max=LLONG_MIN;
      for(int k=i;k<j;k++){
        a = eval(M[i][k], M[k+1][j], exp[2*k+1]);
        b = eval(M[i][k], m[k+1][j],exp[2*k+1]);
        c = eval(m[i][k], M[k+1][j],exp[2*k+1]);
        d = eval(m[i][k], m[k+1][j],exp[2*k+1]);
        Max=max(max(max(max(Max, a),b),c),d);
        Min=min(min(min(min(Min, a),b),c),d);
      }
    m[i][j]=Min;
    M[i][j]=Max;
    }
  }
    return M[0][(n-1)];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}

/*
5-8+7*4-8+9
200

to calculate the ijth element in the matric use the element in the ith row and
jth column 
first compare 1st element in ith row with the uppermost elemnt in the jth column
the secont element with the second uppermost element.
*/