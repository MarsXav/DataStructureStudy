#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node *Find_Min(Node *pNode);

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

Node* Delete(Node* root, int data){
    if (root == nullptr) return root;
    else if (data < root -> data){
        root -> left = Delete(root -> left, data);
    } else if(data > root->data) {
        root -> right = Delete(root->right,data);
    } else {
        //case 1: no child
        if (root -> left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
            return root;
        } else if (root -> left == nullptr) { //case 2: one child
            Node* temp = root;
            root = root -> right;
            delete temp;
            return root;
        } else if(root -> right == nullptr) {
            Node* temp = root;
            root = root -> left;
            delete temp;
            return root;
        } else {//case 3: 2 children
        Node* temp = Find_Min(root->right);
        root -> data = temp -> data;
        root -> right = Delete(root -> right, temp -> data);
        }
    }
    return root;
}

Node* Find_Min(Node* root) {
    if (root == nullptr || root->left == nullptr) {
        return root;
    } else return Find_Min(root->left);
}

void Preorder(vector<int> &res, Node* root){
    if (root == nullptr) return;
    res.push_back(root->data);
    Preorder(res,root->left);
    Preorder(res,root->right);
}

void Print(vector<int>(&res)){
    int len = res.size();
    for (int i = 0; i<len; i++){
        cout << res[i] <<" ";
    }
    cout << endl;
}

int main(){
    Node* root = nullptr;
    root = Insert(root,5); root = Insert(root,3);
    root = Insert(root, 7); root = Insert(root, 2);
    root = Insert(root,4); root = Insert(root,6);
    root = Insert(root, 8);
    root = Delete(root,7);
    vector<int>(res1); cout << "preorder:";
    Preorder(res1,root); Print(res1);
}