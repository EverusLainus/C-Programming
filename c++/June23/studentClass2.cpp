//Assign and print the roll number, phone number and 
//address of two students having names "Sam" and "John" 
//respectively by creating two objects of the class 'Student'.

#include <iostream>
#include <string>
using namespace std;

struct Place{
    int door_no;
    string street;
    string locality;
};

struct Profile{
    string name;
    int roll_no;
    long phone_no;
    Place address;
};

class Student{
    private:
    Profile student;

    public:

//set the detais of the student
    void set(Profile stu){
        Student::student.name=stu.name;
        Student::student.roll_no=stu.roll_no;
        Student::student.phone_no=stu.phone_no;
        Student::student.address=stu.address;
    }

    Profile get_name(){
        return Student::student;
    }

//print the details of the student
    void print(){
        cout <<"Name: "<<student.name<<" "<<" roll_no: "<<student.roll_no
        <<" Phone no : "<<student.phone_no<< " Address :"<<student.address.door_no<<", "
        <<student.address.street<<", "<<student.address.locality<<endl;
    }
};

int main(){

    Student student1;

    //details of student 1
    Place student1p;
    student1p.door_no=2;
    student1p.street="Church Street";
    student1p.locality="London";

    Profile student1pro;
    student1pro.name="John";
    student1pro.roll_no=2;
    student1pro.phone_no=1234567890;
    student1pro.address=student1p;

    student1.set(student1pro);
    student1.print();

    Student student2;

    //details of student 2;
    Place student2p;
    student2p.door_no=34;
    student2p.street="See Shore Street";
    student2p.locality="Paris";

    Profile student2pro;
    student2pro.name="Sam";
    student2pro.roll_no=3;
    student2pro.phone_no=9876543210;
    student2pro.address=student2p;

    student2.set(student2pro);
    student2.print();
    
    return 0;
    
}