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
        if(cur == nullptr) return new Node(val);
        else if(val > cur -> val) cur -> right = push(cur -> right, val);
        else if(val < cur -> val) cur -> left = push(cur -> left, val);
        return cur;
    }

    Node * find(Node * cur, int val){
        if(cur == nullptr) return nullptr;
        else if(val == cur -> val) return cur;
        else if(val > cur -> val) return find(cur -> right, val);
        else return find(cur -> left, val);
    }
public:
    BST(){
        root = nullptr;
    }

};