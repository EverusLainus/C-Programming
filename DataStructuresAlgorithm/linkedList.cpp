#include <iostream>
#include <cstdlib>
using namespace std;


struct node{
    int value;
    struct node *next_num;
};

int main()
{
//create three nodes
     node w1;
     node w2;
     node w3;
//assign value in three nodes
    w1.value= 23;
    w2.value= 03;
    w3.value= 2023;

//assign pointer in three nodes
    w1.next_num= &w2;
    w2.next_num= &w3;
    w3.next_num= NULL;

//print node
for(struct node *current = &w1; current->next_num != NULL; current = current->next_num) {
cout <<"the key value in node is "<<current->value<<endl;
cout<<"the addres of next node is"<<current->next_num<<endl;
cout <<"the next value is " << (* current->next_num).value << endl;
    }
    return 0;   
}

