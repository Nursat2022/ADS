#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    stack<int> st;
    deque<int> maxi;
    int mx = INT_MIN;   
    while(n--){
        string s; cin >> s;
        if(s == "add"){
            int x; cin >> x;
            if(x >= mx){
                mx = x;
                maxi.push_back(x);
            }
            else maxi.push_front(x);
            st.push(x);
        }
        else if(s == "delete"){
            if(!st.empty()){
                if(st.top() == mx){
                    maxi.pop_back();
                    if(maxi.empty()) mx = INT_MIN;
                    else mx = maxi.back();
                }
                st.pop();
            }
        }
        else if(s == "getmax"){
            if(st.empty()) cout << "error" << endl;
            else cout << mx << endl;
        }
        else if(s == "getcur"){
            if(st.empty()) cout << "error" << endl;
            else cout << st.top() << endl;   
        }
    }
}