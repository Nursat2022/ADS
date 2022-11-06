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
    Node * root;
    int a[100000];

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node(val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        else if(val < cur -> val) cur -> left = push(cur -> left, val);
        return cur;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }

    void check(Node * cur){
        if (cur == NULL) return;
        int l = toLeft(cur -> left);
        int r = toRight(cur -> right);
        for (int i = 1; i <= min(l, r); i++) a[i]++;
        check(cur -> left);
        check(cur -> right);
    }

    int toLeft(Node * cur){
        if (cur == nullptr) return 0;
        return toLeft(cur -> left) + 1;
    }

    int toRight(Node * cur){
        if (cur == nullptr) return 0;
        return toRight(cur -> right) + 1;
    }
public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void check(){
        check(root);
    }

    void print(int n){
        for(int i = 1; i < n; i++) cout << a[i] << " ";
    }
};

int main(){
    int n; cin >> n;
    BST * tree = new BST();
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree -> push(x);
    }
    tree -> check();
    tree -> print(n);
}