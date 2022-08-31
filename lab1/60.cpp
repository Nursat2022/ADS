#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    deque<int> d;
    while(s != "exit"){
        cin >> s;
        if(s == "push_front"){
            int x; cin >> x;
            d.push_front(x);
            cout << "ok" << endl;
        }
        else if(s == "push_back"){
            int x; cin >> x;
            d.push_back(x);
            cout << "ok" << endl;
        }
        else if(s == "pop_front"){
            cout << d.front() << endl;
            d.pop_front();
        }
        else if(s == "pop_back"){
            cout << d.back() << endl;
            d.pop_back();
        }
        else if(s == "front"){
            cout << d.front() << endl;
        }
        else if(s == "back"){
            cout << d.back() << endl;
        }
        else if(s == "clear"){
            while(!d.empty()){
                d.pop_back();
            }
            cout << "ok" << endl;
        }
        else if(s == "size") cout << d.size() << endl;
    }
    cout << "bye";
}