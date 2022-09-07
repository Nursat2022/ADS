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

class Linkedlist{
    Node * head;
    int size;
public:
    Linkedlist(){
        head = nullptr;
        size = 0;
    }

    void push(int val){
        Node * newNode = new Node(val);
        if(head == nullptr) head = newNode;
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
            cout << "can't insert";
            return;
        }
        Node * newNode = new Node(val);
        if(head == nullptr) head = newNode;
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
        else{
            Node * cur = head;
            int i = 1;
            while(cur != nullptr){
                if(i == pos) cur -> val = val;
                cur = cur -> next;
                i++;
            }
        }
    }

    void sort(){
        if(head == nullptr) return;
        Node * first = head;
        Node * second = nullptr;
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

    void reverse(){
        vector<int> v;
        Node * cur = head;
        while(cur != nullptr){
            v.push_back(cur -> val);
            cur = cur -> next;
        }
        cur = head;
        int index = v.size()-1;
        while(cur != nullptr){
            cur -> val = v[index];
            cur = cur -> next;
            index--;
        }
    }

    void del(int val){
        if(head == nullptr){
            cout << "empty";
            return;
        }
        if(head -> val == val){
            head = head -> next;
        }
        else{
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
            cout << "NO such value";
        }
        size--;
    }

    void del1(int pos){
        if(head == nullptr){
            cout << "empty";
            return;
        }
        if(pos == 1){
            head = head -> next;
        }
        else{
            Node * cur = head;
            Node * prev = nullptr;
            int i = 1;
            while(cur != nullptr){
                if(i == pos){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;
                i++;
            }
            cout << "NO such val";
        }
        size--;
    }



    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << endl;
    }
};

int main(){
    Linkedlist list;
    list.push(4);
    list.push(54);
    list.push(3);
    list.push(44);
    list.print();
    list.reverse();
    list.print();
}