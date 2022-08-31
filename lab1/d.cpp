#include<bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q;
    string s;
    while(s != "exit"){
        cin >> s;
        if(s == "push"){
            int x; cin >> x;
            q.push(x);
            cout << "ok" << endl;
        }
        else if(s == "size"){
            cout << q.size() << endl;
        }
        else if(s == "pop"){
            cout << q.front() << endl;
            q.pop();
        }
        else if(s == "front") cout << q.front() << endl;
        else if(s == "clear"){
            while(q.size() != 0){
                q.pop();
            }
            cout << "ok" << endl;
        }
    }
    cout << "bye";
}