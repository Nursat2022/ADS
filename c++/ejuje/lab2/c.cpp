#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * next;
    Node * prev;

    Node(int val){
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Linkedlist{
public:
    Node * head;
    Node * tail;
    int size = 0;
    Linkedlist(){
        head = nullptr;
        tail = nullptr;
    }

    Node * find(int n){
        Node * cur = head;
        while(--n){
            cur = cur -> next;
        }
        return cur;
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

    void remove(int n){
        Node * need = find(n);
        if(need -> prev && need -> next){
            need -> prev -> next = need -> next;
            need -> next -> prev = need -> prev;
        }
        else if(need -> prev == nullptr && need -> next == nullptr){
            head = tail = nullptr;
        }
        else if(need -> next == nullptr){
            need -> prev -> next = nullptr;
            tail = need -> prev;
        }
        else{ //need -> prev == nullptr
            need -> next -> prev = nullptr;
            head = need -> next;
        }
        size--;
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
    Linkedlist list;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        list.push(x);
    }

    int index = 2;
    n = list.size;
    while(index < n + 1){
        list.remove(index);
        index += 1;
        n = list.size;
    }

    list.print();
}