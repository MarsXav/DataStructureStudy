#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class BinaryTree{
public:
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
        } else if (x <= root -> data) {
            root -> left = Insert(root -> left, x);
        } else if (x > root -> data) {
            root -> right = Insert(root -> right,x);
        }
        return root;
    }

    Node* Find_Min(Node* root){
        if (root == nullptr) return root;
        while(root -> left != nullptr){
            root -> left = Find_Min(root -> left);
        }
        return root;
    }

    Node* Find_Max(Node* root){
        if(root == nullptr) return root;
        while(root -> right != nullptr) {
            root -> right = Find_Max(root-> right);
        }
        return root;
    }

    void Preorder(vector<int> &res, Node* root){
        if (root == nullptr) return;
        res.push_back(root -> data);
        Preorder(res,root->left);
        Preorder(res,root->right);
    }

    void Inorder(vector<int> &res, Node* root){
        if (root == nullptr) return;
        Inorder(res,root->left);
        res.push_back(root->data);
        Inorder(res,root->right);
    }

    void Postorder(vector<int> &res,Node* root){
        if(root == nullptr) return;
        Postorder(res,root->left);
        Postorder(res,root->right);
        res.push_back(root->data);
    }

    void Levelorder(vector<int> &res,Node* root){
        queue<Node*> Q;
        if (root == nullptr) return;
        Q.push(root);
        while(!Q.empty()){
            Node* current = Q.front();
            res.push_back(current -> data);
            if (current->left != nullptr){
                Q.push(current->left);
            }
            if (current->right != nullptr){
                Q.push(current->right);
            }
            Q.pop();
        }
    }

    Node* Find(Node* root, int x){
        if (root == nullptr) return nullptr;
        else if(x == root->data) return root;
        else if (x <= root-> data){
            root -> left = Find(root->left,x);
        } else if (x > root->data) {
            root->right = Find(root->right,x);
        }
        return root;
    }

    int Height(Node* root){
        if (root == nullptr) return -1;
        int left_h = Height(root->left);
        int right_h = Height(root->right);
        return max(left_h,right_h)+1;
    }

    bool Is_greater(Node* root, int data){
        if (root == nullptr) return true;
        if (root -> data >= data
        && Is_greater(root->right,data)
        && Is_greater(root->left,data))
            return true; else return false;
    }
    bool Is_lesser(Node* root, int data){
        if (root == nullptr) return true;
        if(root->data <= data
        && Is_lesser(root->right,data)
        && Is_lesser(root->left,data))
            return true; else return false;
    }
    bool Is_BST(Node* root){
        if (root == nullptr) return true;
        if (Is_lesser(root->left,root->data)
        && Is_greater(root->right,root->data)
        && Is_BST(root->left)
        && Is_BST(root->right)) return true;
        else return false;
    }

    void Print(vector<int> &res){
        for (int i : res){
            cout << i << " ";
        }
    }
};

int main() {
    return 0;
}
