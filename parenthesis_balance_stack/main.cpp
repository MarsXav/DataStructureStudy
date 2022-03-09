#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Are_pair(char opening, char closing){
    if (opening == '(' && closing == ')') {return true;}
    else if (opening == '[' && closing == ']') {return true;}
    else if (opening == '{' && closing == '}') {return true;}
    else return false;
}

bool Is_balanced(string str){
    stack <char> S;
    for (char & i : str){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
            S.push(str[i]);
        } else if (str[i] == ')' || str[i] ==']' || str[i] == '}'){
            if (S.empty() || !Are_pair(S.top(),str[i])){return false;}
            else S.pop();
        }
    }
    return S.empty();
}

int main(){
    string str;
    cin >> str;
    cout << Is_balanced(str);
    return 0;
}
