#include <iostream>
  
using namespace std;

struct Node{
 Node * prev;
 Node * next;
 string val;
 Node(string _val){
  prev = NULL;
  next = NULL;
  val = _val;
 } 
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    Node * newNode = new Node(s);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}
void add_front(string s){   
    Node * newNode = new Node(s);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }
}
bool empty(){
    return head == NULL;
}
void erase_front(){
    if(head -> next == NULL){
        head = NULL;
        tail = NULL;   
    }
    else{
        head = head -> next;
        head -> prev = NULL;
    }
}
void erase_back(){
    if(tail -> prev == NULL){
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail -> prev;
        tail -> next = NULL;
    }
}
string front(){
    return head -> val;
}
string back(){
    return tail -> val;
}
void clear(){
    head = NULL;
    tail = NULL;
}
  
int main()
{
 string s;
    while(cin >> s){
     if(s == "add_front"){
      string t;
      cin >> t;
      add_front(t);
      cout << "ok" << endl;
     }
     if(s == "add_back"){
      string t;
      cin >> t;
      add_back(t);
      cout << "ok" << endl;
     }
     if(s == "erase_front"){
      if(empty()){
       cout << "error" << endl;
      }
      else
      {
       cout << front() << endl;
       erase_front();
      }
     }
     if(s == "erase_back"){
      if(empty()){
       cout << "error" << endl;
      }
      else{
       cout << back() << endl;
       erase_back();
      }
     }
     if(s == "front"){
      if(empty()){
       cout << "error" << endl;
      }
      else{
       cout << front() << endl;
      }
     }
     if(s == "back"){
      if(empty()){
       cout << "error" << endl;
      }
      else{
       cout << back() << endl;
      }
     }
     if(s == "clear"){
      clear();
      cout << "ok" << endl;
     }
     if(s == "exit"){
      cout << "goodbye" << endl;
      break;
     }
     // cout << "hi" << endl;
    }
    return 0;
}