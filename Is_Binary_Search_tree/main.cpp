#include <iostream>
#include <vector>
#include <queue>
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
bool IsLesser(Node* root, int data){
    if(root == nullptr) return true;
    if (root->data <= data
    && IsLesser(root->left,data)
    && IsLesser(root->right,data)) return true;
    else return false;
}

bool IsGreater(Node* root, int data){
    if(root == nullptr) return true;
    if(root->data>=data
    && IsGreater(root->left,data)
    && IsGreater(root->right,data)) return true;
    else return false;
}

bool Is_binary_tree(Node* root){
    if(root == nullptr) {return true;}
    if(IsLesser(root->left,root->data)
    && IsGreater(root->right,root->data)
    && Is_binary_tree(root->left)
    && Is_binary_tree((root->right))) return true;
    else return false;
}

int main(){
    Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 2);
    root = Insert(root, 4);
    root = Insert(root, 6);
    root = Insert(root, 8);
    root = Insert(root, 1);
    cout << Is_binary_tree(root);
}