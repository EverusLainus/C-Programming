// create a circular linked list

#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next;
    Node(){
        Node::next=nullptr;
    }

    Node(int val){
        Node::value=val;
        Node::next=nullptr;
    }
};

class circularList{
    Node *head;
    public:
    circularList(){
        circularList::head=nullptr;
    }
//adds an element next to the last element that was added newly
    void add(int val){
        Node *new_node =new Node(val);
        if(nullptr == head){
            head = new_node;
            new_node->next=new_node;
        }
        else{
            Node *current_node = new_node;
            Node *temp=head->next;
            head->next = current_node;
            current_node->next=temp;
            head= current_node;

        }
    }
//deletes  the first node added to the list
    void del(){
        head->next=head->next->next;
    }

    Node *find(int val){
        Node *find_now =head;
        Node *last_node=head;

        while(find_now->value != val){
            last_node=find_now;
            find_now=find_now->next;
            if(find_now == head){
                return nullptr;
            }
        }
        return last_node;
    }
 //deletes a particular value
    void del_val(int val){
        Node *my_node;
    //get the node befor the node to be deleted
        my_node=find(val);
        if(my_node == head){
            del();
            return;
        }
        if(my_node == nullptr){
            return;
        }
        my_node->next=my_node->next->next;

    }

    void print(){
        Node *now =head;
        do{
            cout <<"val is"<<now->value<<endl;
            now=now->next;
        }while(now != head);
    }
};

int main(){
    circularList my_clist;
    my_clist.add(1);
    my_clist.add(2);
    my_clist.add(3);
    my_clist.add(4);
    my_clist.del_val(2);
    my_clist.del_val(7);
//    my_clist.del();
    my_clist.print();
    return 0;
}