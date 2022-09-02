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
            inOrder(cur -> right);
        }
    }

    void printLeaf(Node * cur){
        if (cur != nullptr){
            printLeaf(cur -> left);
            if(cur -> left != nullptr and cur -> right == nullptr) cout << cur -> val << endl;
            if(cur -> left == nullptr and cur -> right != nullptr) cout << cur -> val << endl;
            printLeaf(cur -> right);
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

    void printLeaf(){
        printLeaf(root);
    }
};

int main(){
    BST tree;
    int n;
    while(cin >> n && n != 0){
        tree.push(n);
    }
    tree.printLeaf();
}