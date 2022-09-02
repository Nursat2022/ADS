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

    void pushBack(int val){
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
    }

    void add(int pos, int val){
        if(pos > size){
            cout << "can't add";
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
    }

    void insert(int pos, int val){
        if(pos > size){
            cout << "can't insert";
            return;
        }
        Node * cur = head;
        int i = 1;
        while(cur != nullptr){
            if(i == pos) cur -> val = val;
            cur = cur -> next;
            i++;
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
            cout << "no such pos";
        }
        size--;
    }

    void sort(){
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
    list.pushBack(5);
    list.pushBack(6);
    list.pushBack(47);
    list.pushBack(48);
    list.print();
    cout << endl;
    list.pushFront(14);
    list.print();
    cout << endl;
    list.add(3, 1234);
    list.print();
    cout << endl;
    list.del(1234);
    list.print();
}