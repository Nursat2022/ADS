#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int val){
        this -> val = val;
        next = nullptr;
    }
};

class Linkedlist{
    Node * head;
    Node * tail;
public:
    Linkedlist(){
        head = tail = nullptr;
    }

    void push(int val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pushFront(int val){
        Node * newNode = new Node(val);
        if(head == nullptr) head = tail = newNode;
        else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void reverse(){
        Node * cur = head;
        Node * prev = nullptr;
        Node * next = nullptr;
        while(cur){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void print(){
        Node * cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};

int main(){
    int n; cin >> n;
    Linkedlist *list = new Linkedlist();
    bool back = true;
    while(n--){
        int q; cin >> q;
        if(q == 1){
            int num; cin >> num;
            (back) ? list -> push(num) : list -> pushFront(num);
        }
        else{
            back = (back) ? false : true;
        }
    }
    if(!back) list -> reverse();
    list -> print();
}

