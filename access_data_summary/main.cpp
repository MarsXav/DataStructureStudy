#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* Insert_at_end(Node* head, int x){
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = nullptr;
    if (head == nullptr){
        head = temp;
    } else {
        Node* temp1 = head;
        while(temp1 -> next != nullptr){
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp;
    }
    return head;
}

void Insert_at_beginning(Node** head, int x){
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = nullptr;
    if (head != nullptr){
        temp -> next = *head;
    }
    *head = temp;
}


Node* Insert_at_middle(Node* head, int x, int n) {
    Node *temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    if (n == 1) {
        temp->next = head;
        head = temp;
    } else {
        Node* temp1 = head;
        for (int i = 0; i < n - 2; i++) {
            temp1 = temp1 -> next;
        }
        temp -> next = temp1 -> next;
        temp1 -> next = temp;
    }
    return head;
}

Node* Delete(Node* head, int n) {
    Node *temp = head;
    if (n == 1) {
        head = head -> next;
    } else {
        for (int i = 0; i < n - 2; i++) {
            temp = temp -> next;
        }
        Node* temp1 = temp -> next;
        temp -> next = temp1 -> next;
    }
    return head;
}

Node* Reverse_list(Node* ptr){
    Node *prev, *current, *next;
    prev = nullptr;
    current = ptr;
    while(current != nullptr){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    ptr = prev;
    return ptr;
}

Node * Reverse_by_recursion(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    } else {
        Node* temp = Reverse_by_recursion(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
}

void Print(Node* head){
    while(head != nullptr){
        cout << head -> data;
        head = head -> next;
    }
}

int main() {
    struct Node* head = nullptr;
    head = Insert_at_end(head,2);
    head = Insert_at_end(head, 5);
    head = Insert_at_end(head, 3);
    Insert_at_beginning(&head,6);
    head = Delete(head,3);
    head = Insert_at_middle(head,9,3);
    head = Reverse_list(head);
    head = Reverse_by_recursion(head);
    Print(head);
    return 0;
}
