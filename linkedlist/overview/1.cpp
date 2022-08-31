#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    string s;
    Node * next;

    Node(int val, string s){
        this->val = val;
        this->s = s;
        next = nullptr;
    }
};

class LinkedList{
    Node * head;
public:
    LinkedList(){
        head = nullptr;
    }

    void push(int val, string s){
        Node * newNode = new Node(val, s);
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
            cout << cur -> val << " " << cur -> s << endl;
            cur = cur -> next;
        }
    }
};

int main(){
    LinkedList list;
    list.push(1, "asdf");
    list.push(2, "asdf");
    list.push(3, "asdf");
    list.push(4, "asdf");
    list.print();
}