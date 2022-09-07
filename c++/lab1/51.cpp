#include<bits/stdc++.h>

using namespace std;

bool check(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' or s[i] == '[' or s[i] == '{') st.push(s[i]);
        else{
            if(st.empty()) return false;
            else if(s[i] == ')' and st.top() == '(') st.pop(); 
            else if(s[i] == ']' and st.top() == '[') st.pop(); 
            else if(s[i] == '}' and st.top() == '{') st.pop();
            else return false; 
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main(){
    string s; cin >> s;
    if(!check(s)) cout << "no";
    else cout << "yes";
}