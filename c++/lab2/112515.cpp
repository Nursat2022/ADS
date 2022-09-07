#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    string word;
    Node * next;

    Node(int val, string word){
        this -> val = val;
        this -> word = word;
        next = nullptr;
    }
};

class LinkedList{
    Node * head;
public:
    LinkedList(){
        head = nullptr;
    }

    void push(int val, string word){
        Node * newNode = new Node(val, word);
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
            // cout << "ERROR";
        }
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

    void check(){
        char z; 
        while(cin >> z){
            int x; cin >> x;
            if(z == '+'){                
                string word;
                getline(cin, word);
                word.erase(word.begin());
                if(head == nullptr){
                    if(x == 1) push(x, word);
                    else if(x > 1){
                        cout << "ERROR";
                        return;
                    }
                }
                else{
                    Node * cur = head;
                    while(cur != nullptr){
                        if(cur -> next == nullptr){
                            if(cur -> val == x){
                                push(x+1, word);
                                swap(cur -> word, cur -> next -> word);
                            }
                            if(x - cur -> val > 1){
                                cout << "ERROR";
                                return;
                            }
                            else if(x - cur -> val == 1){
                                push(x, word);
                                break;
                            }
                        } 
                        cur = cur -> next;
                    }
                }
            } 
            else if(z == '-'){
                Node * cur = head;
                while(cur != nullptr){
                    if(cur -> next == nullptr){
                        if(x > cur -> val){
                            cout << "ERROR";
                            return;
                        }
                        else{
                            del(x);
                            break;
                        }
                    }
                    cur = cur -> next;           
                }
            }
            else if(z == '*'){
                string word;
                getline(cin, word);
                word.erase(word.begin());
                Node * cur = head;
                while(cur != nullptr){
                    if(cur -> next == nullptr and x > cur -> val){
                        cout << "ERROR";
                        return;
                    }
                    if(cur -> val == x){
                        cur -> word = word;
                        break;
                    }
                    cur = cur -> next;
                }
            }
        }
        print();
    }
};

int main(){
    LinkedList list;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char z;
    list.check();
    // while(cin >> z){
    //     list.check(z);
    // }
    // list.print();
}