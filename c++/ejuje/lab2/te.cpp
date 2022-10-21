#include<bits/stdc++.h>

using namespace std;
    
struct Node{
    int val;
    Node * next;
    Node * prev;
    Node(int val){
        this -> val = val;
        next = prev = nullptr;
    }
};

class Linkedlist{
    Node * head;
    Node * tail;
    int size;
public:
    Linkedlist(){
        head = tail = nullptr;
        size = 0;
    }

    void push(int val){
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        size++;
    }

    void print(){
        Node * cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

    Node * find(int n){
        Node * cur = head;
        while(n--){
            cur = cur -> next;
        }
        return cur;
    }

    void remove(int pos){
        Node * need = find(pos);
        if(need -> prev && need -> next){
            need -> prev -> next = need -> next;
            need -> next -> prev = need -> prev;
        }
        else if(!need -> prev && !need -> next){
            head = tail = nullptr;
        }
        else if(need -> prev == nullptr){
            need -> next -> prev = nullptr;
            head = need -> next;
        }
        else{
            tail = need -> prev;
            tail -> next = nullptr;
        }
    }
};

int main(){
    int n; cin >> n;
    Linkedlist list;
    while(n--){
        int x; cin >> x;
        list.push(x);
    }
    int k; cin >> k;
    list.print();
    cout << endl;
    list.remove(k);
    list.print();
}