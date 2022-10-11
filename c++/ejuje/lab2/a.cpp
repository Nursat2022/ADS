#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * next;
    Node * prev;

    Node(int val){
        this -> val = val;
        next = nullptr;
        prev = nullptr;
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
    }

    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

    int offset(int k){
        Node * cur = head;
        int index = 1, i = 1, num = abs(cur -> val - k);
        while(cur != nullptr){
            int distance = abs(cur -> val - k);
            if(distance < num){
                num = distance;
                index = i;
            }
            cur = cur -> next;
            i++;
        }
        return index - 1;
    }
};

int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        list.push(x);
    }
    int k; cin >> k;
    cout << list.offset(k);
}