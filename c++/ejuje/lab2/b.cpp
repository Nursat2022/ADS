#include<bits/stdc++.h>

using namespace std;

struct Node{
    string val;
    Node * next;

    Node(string val){
        this -> val = val;
        next = nullptr;
    }
};

class LinkedList{
public:
    Node * head;
    Node * tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push(string val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void del(){
        head = head -> next;
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
    int k; cin >> k;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        list.push(s);
    }
    for(int i = 0; i < k; i++){
        list.push(list.head -> val);
        list.del();
    }
    list.print();
}