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
    int size;
public:
    Linkedlist(){
        head = nullptr;
        size = 0;
    }

    void pushBack(int val){
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

    void pushFront(int val){
        Node * newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    void add(int pos, int val){
        if(pos > size){
            cout << "can't add";
            return;
        }
        Node * newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node * cur = head;
            int i = 1;
            while(cur != nullptr){
                if(i == pos){
                    newNode -> next = cur -> next;
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
                i++;
            }
        }
        size++;
    }

    void insert(int pos, int val){
        if(pos > size){
            cout << "can't insert";
            return;
        }
        Node * cur = head;
        int i = 1;
        while(cur != nullptr){
            if(i == pos){
                cur -> val = val;
                break;
            }
            cur = cur -> next;
            i++;
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
    list.pushBack(4);
    list.pushBack(5);
    list.pushBack(6);
    list.pushBack(7);
    list.print();
    cout << endl;
    list.pushFront(33);
    list.print();
    cout << endl;
    list.add(2, 16);
    list.print();
    cout << endl;
    list.insert(2, 99);
    list.print();

}