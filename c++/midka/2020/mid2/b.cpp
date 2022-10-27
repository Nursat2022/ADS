#include<bits/stdc++.h>

using namespace std;

struct Node{
    int day;
    int month;
    int year;
    Node * next;
    Node(int day, int month, int year){
        this -> day = day;
        this -> month = month;
        this -> year = year;
        next = nullptr;
    }
};

class Answer{
public:
    Node * mergeSort(Node * head){
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        Node * left = head;
        Node * right = getMiddle(head);
        Node * tmp = right -> next;
        right -> next = nullptr;
        right = tmp;

        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }

    Node * getMiddle(Node * head){
        Node * slow = head;
        Node * fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    Node * merge(Node * left, Node * right){
        Node * tail = new Node(0, 0, 0);
        Node * dummy = tail;

        while(left && right){
            if(cmp(left, right)){
                tail -> next = left;
                left = left -> next;
            }
            else{
                tail -> next = right;
                right = right -> next;
            }
            tail = tail -> next;
        }
        if(left) tail -> next = left;
        if(right) tail -> next = right;
        return dummy -> next;
    }

    bool cmp(Node * left, Node * right){
        if(left -> year == right -> year){
            if(left -> month == right -> month){
                return left -> day <= right -> day;
            }
            return left -> month < right -> month;
        }
        return left -> year < right -> year;
    }
};

class Linkedlist{
public:
    Node * head;
    Node * tail;
    Linkedlist(){
        head = tail = nullptr;
    }

    void push(int day, int month, int year){
        Node * newNode = new Node(day, month, year);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> day << " " << cur -> month << " " << cur -> year << "\n";
            cur = cur -> next;
        }
    }
};

int main(){
    int n; cin >> n;
    Linkedlist list;
    for(int i = 0; i < n; i++){
        int day, month, year;
        cin >> day >> month >> year;
        list.push(day, month, year);
    }

    Answer ans;
    list.head = ans.mergeSort(list.head);
    list.print();
}