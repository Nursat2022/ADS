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
    int cnt = 0;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node (val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    } 

    void levels(Node* cur, int level) {
    if (!cur) return;
    if (level == 0) cnt += cur -> val;
    else {
        levels(cur -> left, level - 1);
        levels(cur -> right, level - 1);
    }
}

public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    int height(){
        return height(root);
    }

    void levels(){
        int h = height();
        cout << h << "\n";
        for(int i = 0; i < h; i++){
            levels(root, i);
            cout << cnt << " ";
            cnt = 0;
        }
    }

};

int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }
    tree.levels();
}