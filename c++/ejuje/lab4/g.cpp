#include <bits/stdc++.h>

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

int height(Node * cur){
    // base case tree is empty
    if (cur == NULL)
        return 0;
 
    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(cur -> left), height(cur -> right));
}
 
// returns max of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// function to Compute height of a tree.
 
// Function to get diameter of a binary tree
int diameter(Node * cur)
{
    // base case where tree is empty
    if (cur == NULL)
        return 0;
 
    // get the height of left and right sub-trees
    int lheight = height(cur -> left);
    int rheight = height(cur -> right);
 
    // get the diameter of left and right sub-trees
    int ldiameter = diameter(cur -> left);
    int rdiameter = diameter(cur -> right);
 
    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree +
    // 1
    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}
 
// UTILITY FUNCTIONS TO TEST diameter() FUNCTION
 
// The function Compute the "height" of a tree. Height is
// the number f nodes along the longest path from the root
// node down to the farthest leaf node.
 
Node * push(Node * cur, int val){
    if(cur == nullptr) return new Node(val);
    if(val < cur -> val) cur -> left = push(cur -> left, val);
    else if(val > cur -> val) cur -> right = push(cur -> right, val);
    return cur;
}
// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
 
// Driver Code
int main()
{
    Node * root = nullptr;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        root = push(root, x);
    }
    cout << diameter(root);
    return 0;
}