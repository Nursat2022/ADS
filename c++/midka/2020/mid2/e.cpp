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
    Node * root;
    vector<int> v;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node(val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        else if(val < cur -> val) cur -> left = push(cur -> left, val);
        return cur;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }

    void check(Node * cur){
        if(cur != nullptr){
            int lheight = height(cur -> left);
            int rheight = height(cur -> right);
            int h = min(lheight, rheight);
            while(h){
                v[h+1]++;
                h--;
            }
            check(cur -> left);
            check(cur -> right);
        }
    }
public:
    BST(int n){
        root = nullptr;
        for(int i = 0; i < n+1; i++){
            v.push_back(0);
        }
    }

    void push(int val){
        root = push(root, val);
    }


    void print(int n){
        for(int i = 2; i <= n; i++){
            cout << v[i] << " ";
        }
    }

    void check(){
        check(root);
    }

    int height(){
        return height(root);
    }

    void triange(Node * cur){
        if(cur == nullptr) return;
        int l = toLeft(cur -> left);
        int r = toRight(cur -> right);
        int num = min(l, r);
        for(int i = 1; i <= num; i++){
            v[i]++;
        }
        triange(cur -> left);
        triange(cur -> right);
    }

    void triange(){
        triange(root);
    }

    int toLeft(Node * cur){
        if(cur == nullptr) return 0;
        return toLeft(cur -> left) + 1;
    }

    int toRight(Node * cur){
        if(cur == nullptr) return 0;
        return toRight(cur -> right) + 1;
    }
};

int main(){
    int n; cin >> n;
    BST *tree = new BST(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree -> push(x);
    }
    tree -> check();
    tree -> print(n);
}