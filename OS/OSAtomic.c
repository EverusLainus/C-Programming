#include <libkern/OSAtomic.h>//for OSAtomicDecrement64()
#include <stdatomic.h>
#include <stdio.h>

int main(){
    atomic_char32_t count= 1;

    //'OSAtomicDecrement64' is deprecated
    //count = OSAtomicDecrement64(&count);

    atomic_fetch_sub(&count, count);//this works
    printf("The variable count is decreased to %u\n", count);

    return 0;
}