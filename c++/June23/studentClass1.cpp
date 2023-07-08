//Create a class named 'Student' with a string variable 'name' 
//and an integer variable 'roll_no'. Assign the value of roll_no as '2' 
//and that of name as "John" by creating an object of the class Student.
#include <iostream>
using namespace std;


class Student{
    private:
    string name;
    int roll_no;

    public:
    void set_name(string s){
        Student::name=s;
    }
    void set_roll_no(int no){
        Student::roll_no=no;
    }
    string get_name(){
        return Student::name;
    }
    int get_roll_no(){
        return Student::roll_no;
    }
};

int main(){
    Student student1;
    student1.set_name("John");
    student1.set_roll_no(2);
    cout << "name of the student "<<student1.get_name()<<" roll_no "<<student1.get_roll_no();
    return 0;
}