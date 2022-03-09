#include <iostream>

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

Node* Insert(Node* root, int x) {
    if (root == nullptr) {
        root = Get_new_node(x);
        return root;
    } else if (x <= root->data) {
        root->left = Insert(root->left, x);
    } else {
        root->right = Insert(root->right,x);
    }

    return root;
}

bool Search(Node* root, int x){
    if (root == nullptr){
        return false;
    } else if (root->data == x){
        return true;
    } else if (x <= root -> data){
        return Search(root->left,x);
    } else {
        return Search(root->right,x);
    }
}

int main() {
    Node* tree = nullptr;
    tree = Insert(tree,5);
    tree = Insert(tree,7);
    tree = Insert(tree,9);
    tree = Insert(tree,6);
    std::cout << Search(tree,8);
    return 0;
}
