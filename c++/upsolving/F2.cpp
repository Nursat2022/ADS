#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
    Node *root;
    int num = 0;

    Node *push(Node *cur, int val){
        if(cur == NULL) return new Node(val);
        else if(val > cur -> val) cur -> right = push(cur -> right, val);
        else if(val < cur -> val) cur -> left = push(cur -> left, val);
        return cur;
    }

    void lev(Node * cur, int level){
        if(cur == nullptr) return;
        num += cur -> val - level;
        lev(cur -> right, level + 1);
        lev(cur -> left, level + 1);
    }
public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    int lev(){
        lev(root, 0);
        return num;
    }
};

int main(){
    int n; 
    cin >> n;
    BST tree;
    while(n--){
        int x; 
        cin >> x;
        tree.push(x);
    }
    cout << tree.lev();
}