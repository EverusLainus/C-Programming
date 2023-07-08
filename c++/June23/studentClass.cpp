//Create a class named 'Student' with a string variable 'name' 
//and an integer variable 'roll_no'. Assign the value of roll_no as '2' 
//and that of name as "John" by creating an object of the class Student.
#include <iostream>
using namespace std;


class Student{
    public:
    string name;
    int roll_no;
};

int main(){
    Student student1;
    student1.name="John";
    student1.roll_no=2;
    cout << "name of the student "<<student1.name<<" roll_no "<<student1.roll_no;
    return 0;
}