//send a function as a parameter to another function
#include <iostream>
using namespace std;

int student(char * name){
    cout <<" name is "<<name<<endl;
    return 0;
}

int score(int a, int(*student)(char *)){
    student("Emma");
    cout << "score is :" <<a<<endl;
    return 0;
}

int main(){
    score(2, student);
    return 0;
}