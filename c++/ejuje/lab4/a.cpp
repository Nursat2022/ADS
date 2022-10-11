#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

class BST{
private:
    Node * root;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node (val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    bool check(string s, Node * cur){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                cur = cur -> left;
            }
            else cur = cur -> right;
            if(cur == nullptr) return false;
        }
        return true;
    }
public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    
    }

    bool check(string s){
        return check(s, root);
    }
};

int main(){
    BST tree;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        if(tree.check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
}