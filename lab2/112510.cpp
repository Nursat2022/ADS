#include<bits/stdc++.h>

using namespace std;

struct Node{
    string word;
    int cnt;
    Node * next;

    Node(string word){
        this -> word = word;
        cnt = 1;
        next = nullptr;
    }
};

class LinkedList{
    Node * head;
public:
    LinkedList(){
        head = nullptr;
    }

    void push(string s){
        Node * newNode = new Node(s);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node * cur = head;
            while(cur != nullptr){
                if(cur -> word == s){
                    cur -> cnt++;
                    break;
                }
                if(cur -> next == nullptr){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
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
                if(first -> word > second -> word){
                    swap(first -> word, second -> word);
                    swap(first -> cnt, second -> cnt);
                }
                second = second -> next;
            }
            first = first -> next;
        }
    }

    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> word << " " << cur -> cnt << endl;
            cur = cur -> next;
        }
    }
};

int main(){
    LinkedList list;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    while(cin >> s){
        list.push(s);
    }
    list.sort();
    list.print();
}