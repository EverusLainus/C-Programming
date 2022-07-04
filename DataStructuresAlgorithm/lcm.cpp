#include <iostream>

using namespace std;

/*
long long lcm_naive(int a, int b) {
    //cout << "a*b is "<< a*b << ""  << endl; 
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;
   
  return (long long) a * b;
}
*/

 int gcd_fast(int a, int b){
    int r=-1;
    if(a<b){
      //cout << "a <b" << endl;
        while(a!=0 ){
            r=b%a;
            b=a;
            a=r;
            if(r==1){
                //cout << "gcd is 1"  << endl;
              return 1;
            }
        }
       //cout << "gcd is" << b <<" " << endl; 
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
                //cout << "gcd is 1"  << endl; 
              return 1;
            }
        }
        //cout << "gcd is" << a <<" " << endl; 
        return a;
    }   
    else{
        return a;
    }
}

long long  lcm_fast( int a,  int b){
    if(a==0 || b==0){
        return 0;
    }
    long long  l=0;
    l =(long long )a * b;
    //cout << "a*b is "<< l << ""  << endl; 
    
    long long  s =((long long  ) l )/( gcd_fast(a,b));
    //cout << "s is "<< s << ""  << endl; 
    return s;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl; 
  return 0;
}