#include<bits/stdc++.h>

using namespace std;

bool ok = true;

struct Node{
    unsigned long val;
    Node * next;
    Node * prev;

    Node(int val){
        this->val = val;
        next = nullptr; 
        this->prev = nullptr;
    }
};

class Linkedlist{
    Node * head = nullptr;
    Node * tail = nullptr;
public:

    void push(unsigned long val){
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

    void remove(unsigned long val){
        Node * cur = head;
        while(cur != nullptr){
            if(cur -> val == val){
                if(cur -> prev){
                    if(cur -> next){
                        cur -> prev -> next = cur -> next;
                        cur -> next -> prev = cur -> prev;
                    }
                    else{
                        tail = cur -> prev;
                        tail -> next = nullptr;
                    }
                    break;
                }         
                else{
                    if(cur -> next){
                        head = cur -> next;
                        head -> prev = nullptr;
                    }
                    else{
                        head = tail = nullptr;
                    }
                    break;
                }   
            }
            cur = cur -> next;
        }        
        if(cur == nullptr){
            cout << "ERROR" << endl;
            ok = false;
            return;
        }
    }

    void sort(){
        if(head == nullptr) return;
        Node * cur = head;
        while(cur){
            Node * nx = cur -> next;
            while(nx){
                if(cur -> val > nx -> val){
                    unsigned long tmp = cur -> val;
                    cur -> val = nx -> val;
                    nx -> val = tmp;
                }
                nx = nx -> next;
            }
            cur = cur -> next;
        }
    }

    bool isempty(){
        return head == nullptr;
    }

    void print(){
        if(head == nullptr){
            cout << "EMPTY";
            return;
        }
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};

int main(){
    Linkedlist list;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    while(cin >> s){
        string n = "";
        for(int i = 1; i < s.size(); i++){
            n += s[i];
        }
        unsigned val = stoi(n);
        if(s[0] == '+'){
            list.push(val);
        }
        else if(s[0] == '-'){
            if(list.isempty()){
                cout << "ERROR";
                return 0;
            }
            else{
                list.remove(val);
                if(!ok){
                    return 0;
                }
            }
        }
    }
}