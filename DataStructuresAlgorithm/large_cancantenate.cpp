#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using std::vector;
using std::string;
      //adjoint 2nd num back and front to find
      //which one forms a big number
int IsBetter(string number, string maxNumber){
  string string1="";
  string string2 ="";
  string1 = number+maxNumber;
  string2 = maxNumber+number;
  return (string1> string2);
}

vector <string> largest_number(vector<string> a, int x) {
  vector <string> large;
  string maxNumber=""; 
            //when size of a is zero- base case
  if(a.size()==0){
    return large;
  }
          //if sixe is not zero
  while(a.size()!=0){
    int max_idx=0;
     maxNumber = a[0]; 
            //compare adjoined pair of every element of a
            // with first element to form large number
    for (size_t i = 1; i < a.size(); i++) {
      if (IsBetter(a[i], maxNumber)){
      maxNumber = a[i];
      max_idx= i;
      }
    }
          //push back max number to large
    large.push_back(maxNumber);
          //erase the max number from a
    a.erase(a.begin()+max_idx);
            //when size of a is 1 push the value back
            //a erase it from a
    if((a.size() == 1)){
      large.push_back(a[0]);
      a.erase(a.begin());
    }  
  }   
  return large;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
   vector<string> b(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  b=largest_number(a,n);
    for (size_t i = 0; i < b.size(); i++) {
     std::cout << b[i];
    }
  return 0;
}

/*
Algorithm
LargestConcatenate(Numbers): yourSalary ← empty string
while Numbers is not empty:
maxNumber ← −∞
for each number in Numbers:
if number ≥ maxNumber: maxNumber ← number
append maxNumber to yourSalary
remove maxNumber from Numbers return yourSalary
*/