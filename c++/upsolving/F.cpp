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
        if(cur == nullptr) return new Node(val);
        else if(val > cur -> val) cur -> right = push(cur -> right, val);
        else if(val < cur -> val) cur -> left = push(cur -> left, val);
        return cur;
    }

    void levels(Node * cur, int level){
        if(cur == nullptr) return;
        cnt += cur -> val - level;
        levels(cur -> right, level + 1);
        levels(cur -> left, level + 1);
    }
public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void levels(){
        levels(root, 0);
    }
};

int main(){
    int n; cin >> n;
    BST tree;
    while(n--){
        int x; cin >> x;
        tree.push(x);
    }
    tree.levels();
    cout << cnt;
}