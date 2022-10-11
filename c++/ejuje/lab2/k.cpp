#include<bits/stdc++.h>

using namespace std;

struct Node{
    pair<bool, char> p;
    Node * next;
    Node * prev;

    Node(char val){
        p.first = true;
        p.second = val;
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

    void push(char val){
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

    void check(){
        Node * cur = head;
        while(cur -> next != nullptr){
            if(cur -> p.second == tail -> p.second){
                cur -> p.first = false;
                tail -> p.first = false;
            }
            cur = cur -> next;
        }
        cur = head;
        while(cur != nullptr){
            if(cur -> p.first == true){
                cout << cur -> p.second << " ";
                return;
            }
            cur = cur -> next;
        }
        cout << -1 << " ";
    }

};

int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            char z; cin >> z;
            list.push(z);
            list.check();
        }
        cout << endl;
        list.head = nullptr;
    }
}

