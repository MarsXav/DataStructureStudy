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

void Preorder(vector<int> &res, Node* root){
    if (root == nullptr) return;
    res.push_back(root->data);
    Preorder(res,root->left);
    Preorder(res,root->right);
}

void Inorder(vector<int> &res, Node*root){
    if(root == nullptr) return;
    Inorder(res, root -> left);
    res.push_back(root -> data);
    Inorder(res, root -> right);
}

void Postorder(vector<int>(&res), Node* root){
    if (root == nullptr) return;
    Postorder(res,root -> left);
    Postorder(res,root -> right);
    res.push_back(root -> data);
}

void Level(vector<int>(&res), Node* root){
    if(root == nullptr) return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* current = Q.front();
        res.push_back(current -> data);
        if(current -> left != nullptr){
            Q.push(current -> left);
        }
        if(current -> right != nullptr){
            Q.push(current -> right);
        }
        Q.pop();
    }
}

void Print(vector<int>(&res)){
    int len = res.size();
    for (int i = 0; i<len; i++){
        cout << res[i] <<" ";
    }
    cout << endl;
}

vector<int> traverse(Node* root){
    Node* temp = root;
    vector<int> res;
    Preorder(res,root);
    Inorder(res,root);
    Postorder(res,root);
    Level(res,root);
    return res;
}

int main() {
    Node* root = nullptr;
    root = Insert(root,5); root = Insert(root,3);
    root = Insert(root, 7); root = Insert(root, 2);
    root = Insert(root,4); root = Insert(root,6);
    root = Insert(root, 8);
    vector<int>(res1); cout << "preorder:";
    Preorder(res1,root); Print(res1);
    vector<int>(res2); cout << "Inorder:";
    Inorder(res2,root); Print(res2);
    vector<int>(res3); cout << "Postoder:";
    Postorder(res3,root); Print(res3);
    vector<int>(res4); cout <<"Level order:";
    Level(res4,root); Print(res4);
    return 0;
}
