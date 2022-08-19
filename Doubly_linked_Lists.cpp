#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node* prev;

};

//Methods

    void print_forward(Node* head){
        Node* walk_node = head;
        while (walk_node != nullptr){
            cout<<walk_node->value<<endl;
            walk_node = walk_node-> next;
        }

    }

    void print_backward(Node* tail){
        Node* walk_node = tail;
        while (walk_node != nullptr){
            cout<<walk_node->value<< endl;
            walk_node = walk_node->prev;
        }
    }







int main(){

    Node* head;
    Node* tail;

    //1st Node
    Node* node1 = new Node();
    node1->value = 4;
    node1->next = nullptr;
    node1->prev = nullptr;
    head = node1;
    tail = node1;


    //2nd Node
    Node* node2 = new Node();
    node2->value = 5;
    node2->next = nullptr;
    node2->prev = tail;
    tail->next= node2;
    tail = node2;

    print_forward(head);
    print_backward(tail);




    return 0;
}