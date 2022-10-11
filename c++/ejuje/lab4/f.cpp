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

    Node * triangles(Node * cur){
        if(cur != nullptr){
            if(cur -> left && cur -> right) cnt++;
            triangles(cur -> left);
            triangles(cur -> right);
        }
    }

public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    int triangles(){
        triangles(root);
        return cnt;
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }
    cout << tree.triangles();
}