#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;

class HeapBuilder {
 private:
  vector<int> data;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> data[i];
    }     
  }

  vector <int> swiftDown(vector <int> data, int i){
    long long min = i;
    long long n= data.size();
    while(min<=(n/2)-1){
      i=min;
      long long l=2*i +1;
      long long r=2*i +2;
      if(l< n && data[i]> data[l]){
        min=l;
      }
      if(r< n && data[min]> data[r]){
        min=r;
      }
      if(i!=min){
        swap(data[i], data[min]);    
        swaps_.push_back(make_pair(i, min));
    }
    else{
      break;
    }
  }
  return data;
}
  

/*
  vector <int> swiftDown(vector <int> data, int i){
 //   cout <<"current edge is "<<i<<endl;
    long long n= data.size();
    long long min = i;
    long long l=2*i +1;
 //   cout << "now left is "<<l<<endl;
    long long r=2*i+2;
//    cout << "now right is "<<r<<endl;
    if(l>= n && r>=n){
//      cout<<"right or left is in last line"<<endl;
        return data;
    }

    if(l< n && data[i]> data[l]){
 //       cout <<" l is less than min"<<endl;
        min=l;
  //      cout <<"min idx is "<<min<<endl;
    }
 //   cout << "arr min and arr r are "<<data[min]<<data[r]<<endl;
    if(r< n && data[min]> data[r]){
  //      cout <<"r is less than min"<<endl;
        min=r;
 //       cout <<"min idx is "<<min<<endl;
    }
    if(i!=min){
 //       cout <<" pair "<< data[i] <<data[min] <<endl; 
        swap(data[i], data[min]); 
  //      cout <<" changes to "<< data[i] <<data[min] <<endl;     
        swaps_.push_back(make_pair(i, min));
 //       cout <<"next edge is "<<data[min]<<endl;
        swiftDown(data, min);
    }

    return data;
  }
*/

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    long long n =data.size();
    for (int i = (floor(n/2)-1) ; i >=0 ; --i){
        data = swiftDown(data, i);
    }
  }

 public:
  void Solve(){
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
