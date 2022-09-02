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
private:
    Node * root;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node (val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    void inOrder(Node * cur){
        if (cur != nullptr){
            cnt++;
            inOrder(cur -> left);
//            cout << cur -> val << " ";
            inOrder(cur -> right);
        }
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

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }
};

int main(){
    BST tree;
    int n;
    while(cin >> n && n != 0){
        tree.push(n);
    }
    tree.inOrder();
    cout << cnt;
}