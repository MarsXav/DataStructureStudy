#include <iostream>
using namespace std;

struct BST_Node{
    int data;
    BST_Node* left;
    BST_Node* right;
};

BST_Node* Get_New_Node(int x){
    BST_Node *temp = new BST_Node();
    temp -> data = x;
    temp -> left = temp -> right = nullptr;
    return temp;
}

BST_Node* Insert(BST_Node* tree, int x){
    if(tree == nullptr){
        tree = Get_New_Node(x);
        return tree;
} else if (x <= tree -> data){
        tree -> left = Insert(tree -> left, x);
    } else {
        tree -> right = Insert(tree->right, x);
    }
    return tree;
}

int Find_min(BST_Node* root){
    if (root == nullptr){
        return -1;
    }
    while(root -> left != nullptr){
        root = root -> left;
    }
    return root -> data;
}

int Find_min_recursion(BST_Node* root){
    if (root == nullptr){
        return -1;
    } else if (root -> left == nullptr){
        return root -> data;
    } else return Find_min_recursion(root -> left);
}

int main() {
    struct BST_Node* tree = nullptr;
    tree = Insert(tree,7);
    tree = Insert(tree,5);
    tree = Insert(tree,6);
    cout << Find_min_recursion(tree);
    cout << Find_min(tree);
    return 0;
}
