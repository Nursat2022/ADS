#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * right;
    Node * left;

    Node(int val){
        this -> val = val;
        right = left = nullptr;
    }
};

class BST{
    private:

    Node * push(Node * cur, int val){
        if(cur == NULL) return new Node(val);
        if(val > cur->val) cur->right = push(cur->right, val);
        if(val < cur->val) cur->left = push(cur->left, val);
        return cur;
    }

    Node * inOrder(Node * cur){
        if(cur != nullptr){
            cout << cur -> val << " ";
            inOrder(cur -> left);
            inOrder(cur -> right);
        }
    }
   
public:
    Node * root;

    BST(){
        root = nullptr;
    }
    
    void push(int val){
        root = push(root, val);
    }

    void inOrder(){
        inOrder(root);
    }

    void show(vector<int> &v, int l, int r){
        int mid = (l + r)/2;
        cout << v[mid] << " ";
        if(l == r) return;
        show(v, l, mid - 1);
        show(v, mid + 1, r);
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < pow(2, n) - 1; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    tree.show(v, 0, v.size()-1);
}