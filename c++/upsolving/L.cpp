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

int cnt = 0;

class BST{
    Node * root;

    Node * push(Node * cur, int val){
        if(!cur) return new Node(val);
        else if(val > cur -> val) cur -> right = push(cur -> right, val);
        else if(val < cur -> val) cur -> left = push(cur -> left, val);
        return cur;
    }

    Node * leaves(Node * cur){
        if(cur){
            if(!cur -> left && !cur -> right) cnt++;
            leaves(cur -> left);
            leaves(cur -> right);
        }
    }
public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void leaves(){
        leaves(root);
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        tree.push(x);
    }
    tree.leaves();
    cout << cnt;
}