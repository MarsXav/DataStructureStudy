#include <iostream>
using namespace std;

class Queue_Linked_List_Implementation{
public:
    struct Node{
        int data;
        Node* next;
    };
    Node* front = nullptr;
    Node* rear = nullptr;

    void Enqueue(int x){
        Node* temp = new Node();
        temp -> data = x;
        temp -> next = nullptr;
        if (front == nullptr && rear == nullptr){
            front = rear = temp; return;
        }
        rear -> next = temp;
        rear = temp;
    }

    void Dequeue(){
        Node* temp = front;
        if (front == nullptr){return;}
        else if (front == rear){
            front = rear = nullptr;
        } else {
            front = front -> next;
        }
        delete temp;
    }

    void Print(){
        while(front != nullptr){
            cout << front -> data;
            front = front -> next;
        }
    }
};



int main() {
    Queue_Linked_List_Implementation Q;
    Q.Enqueue(3); Q.Enqueue(9);
    Q.Enqueue(7); Q.Enqueue(5);
    Q.Dequeue();
    Q.Print();

    return 0;
}
