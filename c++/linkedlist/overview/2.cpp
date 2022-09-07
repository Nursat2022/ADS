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

class Linkedlist{
    Node * head;
public:
    Linkedlist(){
        head = nullptr;
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
    list.push(4);
    list.push(5);
    list.push(6);
    list.push(7);
    list.print();
}