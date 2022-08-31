#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> st;
    string s;
    while(s != "exit"){
        cin >> s;
        if(s == "push"){
            int x; cin >> x;
            st.push(x);
            cout << "ok" << endl;
        }
        else if(s == "size"){
            cout << st.size() << endl;
        }
        else if(s == "pop"){
                if(!st.empty()){
                cout << st.top() << endl;
                st.pop();
                }
                else cout << "error" << endl;
        }
        else if(s == "back"){
            if(!st.empty()) cout << st.top() << endl;
            else cout << "error" << endl;
        }
        else if(s == "clear"){
            while(st.size() != 0){
                st.pop();
            }
            cout << "ok" << endl;
        }
    }
    cout << "bye" << endl;
}