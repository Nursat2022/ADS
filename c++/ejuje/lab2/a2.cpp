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

class Linkedlist{
    Node * head;
    Node * tail;
    int size;
public:
    Linkedlist(){
        head = nullptr;
        size = 0;
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
        size++;
    }

    void removeDuplicates(){
        Node * cur = head;
        while(cur -> next){
            if(cur -> val == cur -> next -> val){
                cur -> next = cur -> next -> next;
            }
            else cur = cur -> next;
        }
    }

    int getCount(){
        int count = 0;
        Node * cur = head;
        while(cur){
            cur = cur -> next;
            count++;
        }
        return count;
    }

    void deleteFirst(){ head = head -> next; }

    void del(int pos){
        if(pos > size) return;
        if(head == nullptr) return;
        else if(pos == 1) head = head -> next;
        else{
            Node * cur = head;
            Node * prev = nullptr;
            int i = 1;
            while(cur){
                if(i == pos){
                    prev -> next = cur -> next;
                    delete cur;
                    break;
                }
                prev = cur;
                cur = cur -> next;
                i++;
            }
        }
        size--;
    }
    
    void print(){
        Node * cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

    Node * getHead(){
        return head;
    }

    int getSize(){ return size; };
};

int main(){
    Linkedlist list;
    int n; cin >> n;
    while(n--){
        string x; cin >> x;
        list.push(x);
    }
    list.removeDuplicates();
    cout << "All in all: " << list.getCount() << endl;
    cout << "Students:" << endl;
    list.print();
}