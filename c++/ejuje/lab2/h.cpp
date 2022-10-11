#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(p == 0){
        node -> next = head;
        head = node;
    }
    else{
        Node * cur = head;
        int i = 0;
        while(cur != nullptr){
            if(i == p-1){
                node -> next = cur -> next;
                cur -> next = node;
                break;
            }
            i++;
            cur = cur -> next;
        }
    }
    return head;
}
 
Node* remove(Node* head, int p){
    if(p == 0){
        head = head -> next;
    }
    else{
        Node * cur = head;
        Node * prev = nullptr;
        int i = 0;
        while(cur != nullptr){
            if(i == p){
                prev -> next = cur -> next;
                delete cur;
                break;
            }
            i++;
            prev = cur;
            cur = cur -> next;
        }
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    Node * cur = head;
    Node * prev = nullptr;
    int i = 0;
    while(cur != nullptr){
        if(p1 == 0){
            head = head -> next;
            break;
        }
        else if(i == p1){
            prev -> next = cur -> next;
            break;
        }
        i++;
        prev = cur;
        cur = cur -> next;
    }
    Node * tmp = cur;
    cur = head;
    prev = nullptr;
    i = 0;
    while(cur != nullptr){
        if(p2 == 0){
            tmp -> next = head;
            head = tmp;
            break;
        }
        else if(i == p2){
            prev -> next = tmp;
            tmp -> next = cur;
            break;
        }
        else if(cur -> next == nullptr){
            cur -> next = tmp;
            tmp -> next = nullptr;
            break;
        }
        i++;
        prev = cur;
        cur = cur -> next;
    }
    return head;
}
 
Node* reverse(Node* head){
    Node * cur = head;
    Node * prev = nullptr;
    Node * next = nullptr;
    while(cur != nullptr){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}


 
void print(Node* head){
    Node * cur = head;
    if(head == nullptr){
        cout << -1 << "\n";
        return;
    }
    while(cur != nullptr){
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    Node * cur = head;
    int i = 0;
    while(cur -> next != nullptr){
        cur = cur -> next;
        i++;
    }
    cur -> next = head;
    cur = head;
    while(x-1){
        cur = cur -> next;
        x--;
    }
    head = cur -> next;
    cur -> next = nullptr;
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    Node * cur = head;
    int i = 0;
    while(cur -> next != nullptr){
        cur = cur -> next;
        i++;
    }
    cur -> next = head;
    int k = i - x;
    cur = head;
    while(k){
        cur = cur -> next;
        k--;
    }
    head = cur -> next;
    cur -> next = nullptr;
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}