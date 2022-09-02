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

    Node * inOrder(Node * cur){
        if(cur != nullptr){
            inOrder(cur -> left);
            cout << cur -> val << " ";
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
    tree.push(3);
    tree.push(15);
    tree.push(12);
    tree.push(9);
    tree.push(10);
    tree.push(16);
    tree.push(19);
    tree.inOrder();
    tree.postOrder();
}