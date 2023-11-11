#include <iostream>
#include<time.h>
#include <stdint.h>
#include <assert.h>

using namespace std;
/*
uint64_t(tv.tv_sec) * 1000000: This part converts the seconds to microseconds. 
It casts tv.tv_sec to an unsigned 64-bit integer (uint64_t) and 
then multiplies it by 1,000,000 to convert seconds to microseconds.

tv.tv_nsec / 1000: This part represents the nanoseconds part of the monotonic time, 
converted to microseconds. It takes the nanoseconds (tv.tv_nsec) and 
divides it by 1000 to convert nanoseconds to microseconds.

The entire expression adds the converted seconds and 
converted nanoseconds to get the total time in microseconds.

*/

int main(){
    struct timespec ts={0,0};
    cout << "time is "<<ts.tv_nsec<<endl;

    //CLOCK_MONOTONIC = Clock that represents monotonic time since some unspecified starting point.
    assert(clock_gettime(CLOCK_MONOTONIC, &ts)== 0);

    //cout << "time is "<<ts.tv_nsec<<endl;
    int a;
    for(int i=0; i<1000000; i++){
        a=i;
    }
    uint64_t time_in_microsec = uint64_t(ts.tv_sec) * 1000000 + ts.tv_nsec / 1000;
    cout << "time after for loop is " << time_in_microsec << endl;
    return 0;
}