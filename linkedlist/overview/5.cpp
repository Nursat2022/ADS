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

    void del(int val){
        if(head == nullptr){
            cout << "Linked List is empty";
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
            cout << "NO such element " << val << endl;
        }
    }

    void del1(int pos){
        if(head == nullptr){
            cout << "Linked list is empty";
            return;
        }
        if(pos == 1){
            head = head -> next;
        }
        else{
            int i = 1;
            Node * cur = head;
            Node * prev = nullptr;
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
            cout << "NO such pos " << pos << endl; 
        }
    }

    bool contains(int val){
        Node * cur = head;
        while(cur != nullptr){
            if(cur -> val == val){
                return true;
            }
            cur = cur -> next;
        }
        return false;
    }

    vector<int> search(int val){
        vector<int> ans;
        Node * cur = head;
        int i = 1;
        while(cur != nullptr){
            if(cur -> val == val){
                ans.push_back(i);
            }
            cur = cur -> next;
            i++;
        }
        return ans;
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
    list.pushBack(5);
    list.pushBack(5);
    list.pushBack(6);
    list.pushBack(7);
    list.print();
    cout << endl;
    // list.del1(3);
    // list.print();
    // list.del1(-3);
    // cout << list.contains(5);
    vector<int> indices = list.search(5);
    for(auto i : indices) cout << i << " ";
}