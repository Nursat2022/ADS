#include<bits/stdc++.h>

using namespace std;

struct Node{
    string surname;
    string name;
    double overall;
    Node * next;
    Node() : surname(""), name(""), overall(4.0), next(nullptr) {}
    Node(string surnam, string nam, double overal) : surname(surnam), name(nam), overall(overal), next(nullptr) {}
};

// struct Node{
//     string surname;
//     string name;
//     double overall;
//     Node * next;
//     Node(string surname, string name, double overall){
//         this -> overall = overall;
//         this -> surname = surname;
//         this -> name = name;
//         next = nullptr;
//     }
// };

class Answer{
public:
    Node * sortList(Node * head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        Node * left = head;
        Node * right = getMiddle(head);
        Node * tmp = right -> next;
        right -> next = NULL;
        right = tmp;

        left = sortList(left);
        right = sortList(right);
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
            tail = tail->next;
        }

        if(left) tail -> next = left;
        else if(right) tail -> next = right;
        
        return dummy -> next;
    }

    bool cmp(Node * a, Node * b){
        if(a -> overall == b -> overall){
            if(a -> surname == b -> surname){
                return a -> name < b -> name;
            }
            return a -> surname < b -> surname;
        }
        return a -> overall < b -> overall;
    }
};

class LinkedList{
public:
    Node * head;
    Node * tail;
    LinkedList(){
        head = tail = nullptr;
    }

    void push(string surname, string name, double overall){
        Node * newNode = new Node(surname, name, overall);
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
        while(cur){
            cout << cur -> surname << " " << cur -> name << " " << fixed << setprecision(3) << cur -> overall << endl;
            cur = cur -> next;
        }
    }
    void print(Node * cur){
        while(cur){
            cout << cur -> surname << " " << cur -> name << " " << fixed << setprecision(3) << cur -> overall << endl;
            cur = cur -> next;
        }
    }
};

int main(){
    int n; cin >> n;
    map<string, double> mp;
    LinkedList list;
    mp["A+"] = 4.0;
    mp["A"] = 3.75;
    mp["B+"] = 3.5;
    mp["B"] = 3.0;
    mp["C+"] = 2.5;
    mp["C"] = 2.0;
    mp["D+"] = 1.5;
    mp["D"] = 1.0;
    mp["F"] = 0;

    for(int i = 0; i < n; i++){
        string surname, name;
        cin >> surname >> name;
        int m; cin >> m;
        double sum = 0, sum2 = 0;
        while(m--){
            string mark; int credits;
            cin >> mark >> credits;
            sum += mp[mark] * credits;
            sum2 += credits;
        }
        list.push(surname, name, sum/sum2);
    }
    Answer ans;
    // list.print(ans.sortList(list.head));
    list.head = ans.sortList(list.head);
    list.print();
}