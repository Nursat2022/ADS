#include<bits/stdc++.h>

using namespace std;

bool ok = true;
int size = 0;

struct Node{
    string word;
    Node * next;
    Node * prev;

    Node(string word){
        this->word = word;
        next = nullptr; 
        prev = nullptr;
    }
};

class Linkedlist{
    Node * head = nullptr;
    Node * tail = nullptr;
public:

    void push(int n, string word){
        Node * newNode = new Node(word);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            Node * need = find(n);
            if(need == nullptr){
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = newNode;
            }
            else if(need -> prev){
                need -> prev -> next = newNode;
                newNode -> prev = need -> prev;
                newNode -> next = need;
                need -> prev = newNode;
            }
            else{
                newNode -> next = head;
                head -> prev = newNode;
                head = newNode;
            }
        }
    }

    Node * find(int n){
        Node * cur = head;
        while(--n){
            cur = cur -> next;
        }
        return cur;
    }

    void remove(int n){
        Node * need = find(n);
        if(need -> prev && need -> next != nullptr){
            need -> prev -> next = need -> next;
            need -> next -> prev = need -> prev;
        }
        else if(need -> prev == nullptr && need -> next == nullptr){
            head = tail = nullptr;
        }
        else if(need -> next == nullptr){
            need -> prev -> next = nullptr;
            tail = need -> prev;
        }
        else{
            need -> next -> prev = nullptr;
            head = need -> next;
        }
    }

    void replace(int n, string word){
        Node * need = find(n);
        need -> word = word;
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
            cout << cur -> word << endl;
            cur = cur -> next;
        }
    }
};

int main(){
    Linkedlist list;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    char z;
    int x; 
    string s;
    while(cin >> z >> x){
        getline(cin, s);
        s.erase(0, 1);
        if(z == '+'){
            if(x > size + 1){
                cout << "ERROR";
                return 0;
            }
            list.push(x, s);
            size++;
        }
        else if(z == '-'){
            if(x > size || size <= 0){
                cout << "ERROR";
                return 0;
            }
            else list.remove(x);
            size--;
        }
        else if(z == '*'){
            if(x > size || size == 0){
                cout << "ERROR";
                return 0;
            }
            list.replace(x, s);
        }
    }
    if(size == 0) cout << "EMPTY";
    else list.print();
}