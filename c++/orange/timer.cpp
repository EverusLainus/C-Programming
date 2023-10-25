#include <iostream>
#include <chrono>

using namespace std;

struct timer{
    chrono::time_point<chrono::steady_clock> start, end;
    chrono::duration<float> duration;
    timer(){
        start = chrono::high_resolution_clock::now();
    }
    ~timer(){
        end = chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count()*1000.0f;
        cout <<"duration is "<< ms;
    }
};

void print(){
    for(int i=0; i<25; i++){
        cout << "FAITH ";
    }
    cout <<endl;
}

int main(){
    timer t;
    print();
    return 0;
}