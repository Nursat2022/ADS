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

    Node * printSubtree(int k, Node * cur){
        if(cur != nullptr){
            cout << cur -> val << " ";
            printSubtree(k, cur -> left);
            printSubtree(k, cur -> right);
        }     
    }

    Node * find(Node * cur, int k){
        if(cur == nullptr) return nullptr;
        else if(cur -> val == k) return cur;
        else if(cur -> val < k) return find(cur -> right, k);
        else return find(cur -> left, k);
    }

public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void printSubtree(int k){
        printSubtree(k, find(root, k));
    }

};

int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }
    int k; cin >> k;
    tree.printSubtree(k);
}