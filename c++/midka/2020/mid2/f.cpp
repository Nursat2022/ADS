#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        left = right = nullptr;
    }
};

class BST{
    Node * root;
public:
    BST(){
        root = nullptr;
    }

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node(val);
        else if(val > cur -> val) cur -> right = push(cur -> right, val);
        else if(val < cur -> val) cur -> left = push(cur -> left, val);
        return cur;
    }

};

void print(vector<int> &v, int l, int r){
    if(l > r) return;
    int mid = (l + r)/2;
    cout << v[mid] << " ";
    print(v, l, mid - 1);  
    print(v, mid + 1, r);  
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    print(v, 0, v.size()-1);
}