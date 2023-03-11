#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;
  int midpoint;
  while(right >= left){
    midpoint = (left + right)/2;
    if(a[midpoint] == x){
        return midpoint;
    }
    if (a[midpoint] < x){
        left = midpoint+1;
        //cout << left << endl;
        continue;
        
    }
    if (a[midpoint] > x){
        right = midpoint-1;
        //cout << right << endl;
    }
  }
  return -1;
}
/*
int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}
*/
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  return 0;
}

/*
count from 0 to size-1
for each i
    find midpoint of start and end
    if midpoint equals ith value b[i]
        return i
    if midpoint < ith value
        start = i
    if midpoint > ith value
        end =i       
*/