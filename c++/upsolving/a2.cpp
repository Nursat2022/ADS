#include <iostream>

using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;

    Node (int val){
        this->val = val;
        left = right = nullptr;
    }
};
class BST{
    Node *root;
private:
    BST(){
        root = nullptr;
    }
    Node *push(Node *cur, int val){
        if(root == nullptr){
            return new Node(val);
        }
        if(val < left->val){
            
        }
    }
};
int main (){

}