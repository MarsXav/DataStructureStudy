#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* letters[26];
    bool flag = false;

    bool containsKey(char ch){
        return (letters[ch-'a'] != nullptr);
    }

    void put(char ch, Node* node){
        letters[ch - 'a'] = node;
    }

    Node* next(char ch){
        return letters[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for (char& ch : word){
            if (!node ->containsKey(ch)){
                node -> put(ch, new Node());
            }
            node = node -> next(ch);
        }
        node -> setEnd();
    }

    bool search (string word){
        Node* node = root;
        for (char& ch : word){
            if (!node ->containsKey(ch)) {
                return false;
            }
            node = node -> next(ch);
        }
        return node ->isEnd();
    }

    bool searchStart(string prefix){
        Node* node = root;
        for (char& ch : prefix){
            if (!node ->containsKey(ch)){
                return false;
            }
            node = node ->next(ch);
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj -> insert("apple");
    bool param1 = obj ->search("apple");
    bool param2 = obj -> search("app");
    bool param3 = obj ->searchStart("app");
    cout << param1 << param2 << param3 << endl;
    return 0;
}
