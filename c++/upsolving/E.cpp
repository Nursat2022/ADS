#include<iostream>
#include <stack>

using namespace std;

int getSecondMax(stack<int> st){
    int mx = INT_MIN;
    while(!st.empty()){
        if(st.top() > mx) mx = st.top();
        st.pop();
    }
    return mx;
}

int main(){
    int n; cin >> n;
    int mx = INT_MIN;
    stack<int> st;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "add"){
            int x; cin >> x;
            if(x > mx) mx = x;
            st.push(x);
        }
        else if(s == "delete"){
            if(st.empty()) cout << "error" << endl;
            else{
                if(st.top() == mx){
                    st.pop();
                    mx = getSecondMax(st);
                }
                else st.pop();
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