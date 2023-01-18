#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector <int> merge(vector<int>  b,vector<int>  c){
        //make empty vector
    vector<int> D(0);
        //if both b and c are nonempty
        //chect the smalest in 1st element of each
    while(b.size()!= 0 && c.size()!=0){
        if(b[0]<=c[0]){
            D.push_back(b[0]);
            b.erase(b.begin());
        }
        else{
            D.push_back(c[0]);
            c.erase(c.begin());
        }
    }
       //put the remaining elts in d
    if(b.size()>0){
        for(int i=0; i<b.size();i++){
            D.push_back(b[i]);
        }
    }
    if(c.size()>0){
        for(int i=0; i<c.size();i++){
            D.push_back(c[i]);
        }
    }
        //return new vector
    return D;
}

vector <int> merge_sort(vector<int> a, int l, int r){
    vector<int> b(m+1-l);
    vector<int> B(m+1-l);
    vector<int> c(r-m);
    vector<int> C(r-m);
    vector <int>A(a.size());
    int j=0;

        //if size of a is 1 return a
    if(a.size()==1){
        return a;
    }
        //find midpoint of l and r
    int m =(l+r)/2;
        //put first m elts in b
    for(int i=l; i<= m;i++){       
        b[j]=a[i];
        j++;
    }
        //sort b
    B=merge_sort(b, 0,b.size()-1);
        //put remain elts of a in c
    int k=0;
    for(int i= m+1; i<=r;i++){ 
        c[k]=a[i];
        k++;
    }
        //sort c
    C=merge_sort(c, 0,c.size()-1);
        //sort the whole a
    A= merge(B,C);
    return A;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  vector<int> T(n);

  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  T= merge_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < T.size(); ++i) {
    std::cout << T[i] << ' ';
  }
  return 0;
}

