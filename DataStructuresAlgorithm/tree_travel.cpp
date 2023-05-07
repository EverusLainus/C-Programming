#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;
using namespace std;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    vector<int> result;
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  vector <int> in_order() {
    vector<int> inOrder;
    stack<int> st;
    int idx=0;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    while(idx!=-1|| (st.empty()==0)){
      while(idx!=-1){  
        st.push(idx);//push the index     
        idx=left[idx];       
      }
      idx=st.top();
      st.pop();
      inOrder.push_back(key[idx]);
      idx=right[idx];
    }
    return inOrder;
  }

  vector <int> pre_order() {
 //       cout<<"in pre_order "<<endl;
 //same a in order code; instead of pushing in while loop 
 //we push after out from while loop
    int idx=0;
    stack<int> st;
    vector<int> preOrder;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
        while(idx!=-1|| (st.empty()==0)){
      while(idx!=-1){ //travel through left till end
        st.push(idx);//push the index 
        preOrder.push_back(key[idx]);    
        idx=left[idx];       
      }
      idx=st.top();
      st.pop();
      //make right idx next node(if it exist )
      idx=right[idx];
    }
    
    return preOrder;
  }

  vector <int> post_order() {
//traverse thru left idx and push key twice; the pop the top. 
//if top is same as idx go to right idx
//else push the key and make index null
    vector<int> postOrder;
    int idx=0;
    stack<int> st;
    // Finish the implementation
    // You may need to add a new recursive method to do that
      while(idx!=-1|| (st.empty()==0)){
      while(idx!=-1){        
        st.push(idx);//push the index 
        st.push(idx);//push the index 
        //postOrder.push_back(key[idx]);    
        idx=left[idx];       
      }
        idx=st.top();
        st.pop(); 
      if((st.empty()==0) && st.top()== idx){
        idx=right[idx]; 
      }
      else{
       postOrder.push_back(key[idx]);
       idx=-1;
      }
    }    
    return postOrder;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

/*
5
4 1 2
2 3 4
5 -1 -1
1 -1 -1
3 -1 -1

12345 42135 13254

10
0 7 2
10 -1 -1 
20 -1 6 
30 8 9 
40 3 -1 
50 -1 -1 
60 1 -1 
70 5 4 
80 -1 -1 
90 -1 -1

50 70 80 30 90 40 0 20 10 60
0 70 50 40 30 80 90 20 60 10
50 80 90 30 40 70 10 60 20 0
*/