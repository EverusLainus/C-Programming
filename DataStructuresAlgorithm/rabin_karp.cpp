#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
using std::string;
using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

//hash function
//polynomial hash function
   ull hash_func(const string& s, int idx){
        static const size_t x = 1;//choose x \in (1,p-1)
        static const size_t p= 1000000003;
        ull hash = 0;
        ull length =s.size();
        int number=0;
        for (long long i = idx; i <idx+length; ++i){
            number =int(s[i-idx]);
            ull a=number*(pow(x,i-idx));
            hash=(hash+a)%p;
        }    
        return hash;
    }


vector <ull> precomputeHash(const string& t, ull slen){
    int x=1;
    ull p= 1000000003;
    
    ull tlen=t.length();//length of original string
    vector <ull> H(tlen-slen+1);
    string name;   
    name =t.substr(tlen-slen, slen);
    H[tlen-slen]=hash_func(name,tlen-slen );
    ull y=1;

    //find \sum_1^slen x^n
    for(long long i=1; i<slen+1; i++){
        y=(ull)((y*x)%p);
   }

    //recurence relation betweent two values of hash function
    //find one hash value from pervious hash value and save time
    for(long long i=tlen-slen-1; i>=0; i--){
        int num=int(t[i]);
        int num1=int(t[i+slen]);
        ull one= (ull )((x*H[i+1]+num -(y*num1))%p);              
        ull two=(ull)(one+p)%p;
        H[i]=two;
    }
    return H;
}

//take input
Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}
//print output
void print_occurrences(const std::vector<ull>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}
//process data
std::vector<ull> get_occurrences(const Data& input) {
    const string s = input.pattern, t = input.text;
    std::vector<ull> ans;//output vector
    long long tlen=t.length();
    long long slen=s.length();
    vector <ull> Ha(tlen-slen+1);
    
        ull hashs =0;
        hashs = hash_func(s,0);//hash of P substring
        Ha = precomputeHash(t,s.length());
        ull sizet = t.size()-s.size();
        for(int i=0; i<= sizet;  i++){
           if(Ha[i]!= hashs){
             continue;
           }//now hasht=hashp
           string sub1 =  t.substr(i,s.size());
           if(s==sub1){
            ans.push_back(i);
           }
        }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}

/*
aba
abacaba
0 4

Test
testTesttesT

aaaaa
baaaaaaab
*/