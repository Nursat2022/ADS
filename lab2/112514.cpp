#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node * next;

    Node(int val){
        this -> val = val;
        next = nullptr;
    }
};

class LinkedList{
    Node * head;
public:
    LinkedList(){
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

   void del(int val){
        if(head == nullptr){
            cout << "EMPTY";
            return;
        }
        if(head -> val == val){
            head = head -> next;
        }
        else{
            bool ok = true;
            Node * cur = head;
            Node * prev = nullptr;
            while(cur != nullptr){
                if(cur -> val == val){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;
            }
            cout << "ERROR";
        }
    }

    bool nonempty(){
        if(head == nullptr) return false;
        return true;
    }

    void sort(){
        Node * first = head;
        Node * second = nullptr;
        if(head == nullptr){
            return;
        }
        while(first -> next != nullptr){
            second = first -> next;
            while(second != nullptr){
                if(first -> val > second -> val){
                    swap(first -> val, second -> val);
                }
                second = second -> next;
            }
            first = first -> next;
        }
    }

    bool exist(int val){
        Node * cur = head;
        while(cur != nullptr){
            if(cur -> val == val) return true;
            cur = cur -> next;
        }
        return false;
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
    LinkedList list;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char z; int x;
    while(cin >> z){
        cin >> x;
        if(z == '+') list.push(x);
        else if(z == '-'){
            if(!list.exist(x)){
                cout << "ERROR";
                return 0;
            }
            list.del(x);
        };
    }
    list.sort();
    list.print();
    
}