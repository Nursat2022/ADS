#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * next;

    Node(int val){
        this->val = val;
        next = nullptr;
    }
};

class LinkedList{
    Node * head;
    int size;
public:
    LinkedList(){
        head = nullptr;
        size = 0;
    }

    void push(int val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node * cur = head;
            while(cur != nullptr){
                if(cur -> next == nullptr){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
        size++;
    }

    vector<int> res(){
        vector<int> ans;
        int i = 1;
        Node * cur = head;
        while(cur != nullptr){
            if(i >= size/2 + 1){
                ans.push_back(cur -> val);
            }
            cur = cur -> next;
            i++;
        }
        return ans;
    }

    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};

int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        list.push(x);
    }
    vector<int> rave = list.res();
    for(auto i : rave) cout << i << " ";
}