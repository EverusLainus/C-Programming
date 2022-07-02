#include <iostream>

using namespace std;

/*
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}*/

int gcd_fast(int a, int b){
    int r=-1;
    if(a<b){
      //cout << "a <b" << endl;
        while(a!=0 ){
            r=b%a;
            b=a;
            a=r;
            if(r==1){
              return 1;
            }
        }
      return b;
    }
    
    else if(b<a){
      //cout << "b <a" << endl;
        while(b!=0 ){
            r=a%b;
            //cout << r << endl;
            a=b;
            b=r;
            if(r==1){
              return 1;
            }
        }
        return a;
    }
    
    else{
        return a;
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
