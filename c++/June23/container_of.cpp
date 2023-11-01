#include <iostream>
#include <string>
#define container_of(ptr, type, member) ({                  \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type, member) );})

using namespace std;

struct Table{  
    vector <int> data[5];
    string name;
};

void fill_in(string &str){
    printf("pointer to the string in struct Table %d\n", &str);

    struct Table *T_ptr = container_of(&str, Table, name);
    printf("pointer to the struct Table %d\n", T_ptr);
}

int main(){
    struct Table T;
    T.name = "lainus";
    fill_in(T.name);
    return 0;
}