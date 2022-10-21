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
    map<int, int> levelSum;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node (val);
        if(val < cur -> val) cur -> left = push(cur -> left, val);
        if(val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    } 

    void getLevelsSum(Node* cur, int level) {
        if (!cur) return;
        levelSum[level] += cur -> val;
        getLevelsSum(cur -> right, level + 1);
        getLevelsSum(cur -> left, level + 1);
    }
public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    int height(){
        return height(root);
    }

    void getLevelsSum(){
        getLevelsSum(root, 0);
    }

    vector<int> res(){
        vector<int> ans;
        for(auto i : levelSum){
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tree.push(x);
    }
    tree.getLevelsSum();
    for(auto i : tree.res()) cout << i << " ";
}