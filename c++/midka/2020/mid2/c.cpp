#include<bits/stdc++.h>

using namespace std;

struct Node{
    char val;
    Node * next;
    Node() : val('a'), next(nullptr) {}
    Node(char x) : val(x), next(nullptr) {}
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
        Node * tail = new Node();
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

    bool isVowel(char z){
        if(z == 'a' || z == 'e' || z == 'o' || z == 'i' || z == 'u'){
            return true;
        }
        return false;
    }

    bool cmp(Node * left, Node * right){
        return ((isVowel(left -> val) && isVowel(right ->val) || (!isVowel(left -> val) && !isVowel(right -> val)) && left -> val < right -> val) || (isVowel(left -> val) && !isVowel(right -> val)));
    }
};

class Linkedlist{
public:
    Node * head;
    Node * tail;
    Linkedlist(){
        head = tail = nullptr;
    }

    void push(char val){
        Node * newNode = new Node(val);
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
            cout << cur -> val;
            cur = cur -> next;
        }
    }
};

int main(){
    int n; cin >> n;
    Linkedlist list;
    for(int i = 0; i < n; i++){
        char z; cin >> z;
        list.push(z);
    }

    Answer ans;
    list.head = ans.mergeSort(list.head);
    list.print();
}