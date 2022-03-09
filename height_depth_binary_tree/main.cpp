#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* Get_new_node(int x){
    Node* temp = new Node();
    temp -> data = x;
    temp -> left = temp -> right = nullptr;
    return temp;
}

Node* Insert(Node* root, int x){
    if (root == nullptr){
        root = Get_new_node(x);
        return root;
    } else if (x <= root ->data) {
        root -> left = Insert(root -> left,x);
    } else if (x > root -> data) {
        root -> right = Insert(root -> right,x);
    }
    return root;
}

int FindHeight(Node* root){
    if (root == nullptr){
        return -1;
    }
    int left_height = FindHeight(root -> left);
    int right_height = FindHeight(root -> right);
    return max(left_height,right_height)+1;
}

int main() {
    struct Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root,4);
    root = Insert(root,8);
    root = Insert(root,1);
    cout << FindHeight(root);
    return 0;
}
