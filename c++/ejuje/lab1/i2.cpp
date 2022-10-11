#include<bits/stdc++.h>

using namespace std;

string winner(queue<int> q1, queue<int> q2, int n){
    while(!q1.empty() && !q2.empty()){
        if(q1.front() < q2.front()){
            q1.push(q1.front() + n);
        }
        else{
            q2.push(q2.front() + n);
        }
        q1.pop();
        q2.pop();
    }
    if(q1.empty()) return "SAKAYANAGI";
    return "KATSURAGI";
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    queue<int> q1, q2;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'K') q1.push(i);
        else q2.push(i);
    }

    cout << winner(q1, q2, n);
}