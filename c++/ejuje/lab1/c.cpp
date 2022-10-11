#include<bits/stdc++.h>

using namespace std;

string result(string s){
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.size(); i++){   
        if(s[i] == '#') st.pop();
        else st.push(s[i]);
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    string s, t;
    cin >> s >> t;
    if(result(s) == result(t)) cout << "Yes";
    else cout << "No";
}