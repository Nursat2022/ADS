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

class Bst { 
private: 
 
    struct Node{ 
 
        Node(int x) { 
            val = x; 
        } 
 
        int val; 
        Node *left = nullptr; 
        Node *right = nullptr; 
    }; 
 
    Node *root = nullptr; 
 
    void add(Node *node, int x) { 
        if(node->val > x) { 
            if (node->left) 
                add(node->left, x); 
            else 
                node->left = new Node(x); 
        } else { 
            if(node->right) 
                add(node->right, x); 
            else 
                node->right = new Node(x); 
        } 
    } 
 
    int sizeOfNode(Node *node, int x, bool used) { 
        if(!node) 
            return 0; 
        if(node->val == x) 
            used = true; 
        return used + sizeOfNode(node->right, x, used) + sizeOfNode(node->left, x, used); 
    } 
 
public: 
 
    void add(int x) { 
        if(!root) 
            root = new Node(x); 
        else 
            add(root, x); 
    } 
 
    int sizeOfNode(int x) { 
        return sizeOfNode(root, x, false); 
    } 
 
}; 
 
int main() { 
 
    Bst bst; 
 
    int n; 
    cin >> n; 
    for(int i = 0 ; i < n; i++) { 
        int x; 
        cin >> x; 
        bst.add(x); 
    } 
 
    int x; 
    cin >> x; 
    cout << bst.sizeOfNode(x); 
 
 
    return 0; 
}