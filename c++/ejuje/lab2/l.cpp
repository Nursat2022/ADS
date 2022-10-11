# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
    Node * first = head;
    Node * second = nullptr;
        int mx = first -> val, cnt;
        while(first -> next != nullptr){
            cnt = first -> val;
            second = first -> next;
            while(second != nullptr){
                mx = max(mx, max(cnt, cnt + second -> val));
                cnt += second -> val;
                second = second -> next;
            }
            first = first -> next;
        }
        return mx;
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}