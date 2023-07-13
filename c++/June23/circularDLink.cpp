//create a circular doubly linked list

#include<iostream>
using namespace std;

class Node{
    public:
    Node *pre;
    int value;
    Node *next;
    
    Node(int val){
        Node::value=val;
        Node::next=nullptr;
        Node::pre=nullptr;
    }
};

class circular_dList{
    
    Node *head;
    public:
    circular_dList(){
        circular_dList::head=nullptr;
    }

    void add(int val){
        Node *new_node = new Node(val);

        if(head==nullptr){
            head=new_node;
            new_node->next=new_node;
            new_node->pre=new_node;
        }
        else{
            Node *current_node = head;
            Node *temp =current_node->next;
            current_node->next=new_node;
            new_node->pre=current_node;
            new_node->next=temp;
            temp->pre=new_node;
            head=new_node;
            
        }
    }

    void del(){
        Node *last_head=head;
        head=head->pre;
        if(head == last_head){
            head =nullptr;
            return;
        }   
        
        head->next=last_head->next;
        last_head->next->pre=head;
    }

    void print(){
        Node *now = head;
        if(head == nullptr){
            return;
       }
        do{
            cout <<"val is"<<now->value<<endl;
            now=now->pre;

        }while(now!=head);
    }
};

int main(){
    circular_dList my_circular_dlist;
    my_circular_dlist.add(1);
    my_circular_dlist.add(2);
    my_circular_dlist.add(3);
    my_circular_dlist.del();
    my_circular_dlist.print();
    my_circular_dlist.del();
    my_circular_dlist.print();
    my_circular_dlist.del();
    my_circular_dlist.print();
    return 0;
}