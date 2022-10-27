#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    int cnt;
    Node(int val){
        cnt = 1;
        this -> val = val;
        left = right = nullptr;
    }
};

class BST{
private:
    Node * root;

    Node * push(Node * cur, int val){
        if(!cur) return new Node(val);
        if(cur -> val == val) cur -> cnt++;
        else if(val > cur -> val) cur -> right = push(cur -> right, val);
        else if(val < cur -> val) cur -> left = push(cur -> left, val);
        return cur;
    }

    void show(Node * cur, int val){
        if(cur == nullptr){
            cout << 0 << endl;
            return;
        }
        if(cur -> val == val){
            cout << cur -> cnt << endl;
            return;
        }
        if(cur -> val > val){
            show(cur -> left, val);
        }
        if(cur -> val < val){
            show(cur -> right, val);
        }
    }

    void del(Node * cur, int val){
        if(cur == nullptr) return;
        if(cur -> val == val){
            if(cur -> cnt > 0) cur -> cnt--;
            return;
        }
        if(cur -> val > val) del(cur -> left, val);
        if(cur -> val < val) del(cur -> right, val);
    }
public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void show(int val){
        show(root, val);
    }
};

int main(){

}