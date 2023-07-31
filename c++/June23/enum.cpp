//enumerated type

#include<iostream>

using namespace std;

//if i give values for enum variables in definition the unassigned
//variables takes values added one
//MONDAY=-2, WEDNESDAY=3
//-2,-1,3,4,5,6,7
enum weekday{
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

//throw err:  redefinition of enumerator 'SATURDAY', "SUNDAY"
//enum weekend{
//    SATURDAY, SUNDAY
//};

weekday operator+ (weekday day, int num){
    return weekday ((weekday ((int) day +num))%7);
}

int main(){
    int integer;

    integer= MONDAY;
    cout <<integer <<endl;//prints 0

//    weekday MONDAY = -1; //"MONDAY" is not modifiable lvalue

    weekday TUESDAY = static_cast<weekday>(0);//TUESDAY becomes 0
    cout <<TUESDAY<<endl;

    weekday WEDNESDAY = weekday (0);//WEDNESDAY becomes 0
    cout <<WEDNESDAY<<endl;
    cout <<SUNDAY<<endl;

    cout <<SUNDAY+1<<endl;
    return 0;
}