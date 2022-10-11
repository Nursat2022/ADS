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

    Node * inOrder(Node * cur){
        if(cur != nullptr){
            inOrder(cur -> left);
            cout << cur -> val << " ";
            inOrder(cur -> right);
        }
    }

    Node * need(bool ok, int k, Node * cur){
        if(cur != nullptr){
            need(ok, k, cur -> left);
            cnt++;
            need(ok, k, cur -> right);
        }
    }

    Node* find(Node* root, int x) {
        if (root == nullptr) return nullptr;
        else if (root -> val == x) return root;
        else if (root -> val < x) return find(root -> right, x);
        else return find(root -> left, x);
    }

    Node * postOrder(Node * cur){
        if(cur != nullptr){
            postOrder(cur -> right);
            cout << cur -> val << " ";
            postOrder(cur -> left);
        }
    }

public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    
    }

    int subtree(int k){
        need(true, k, find(root, k));
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
    int k; cin >> k;
    cout << tree.subtree(k);
}