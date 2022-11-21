#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> prefix_function(string s){
    int n = (int) s.length();
    vector<int> pi(n);
    for(int i = 1;  i < n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string s, t;
    int n;
    cin >> t >> n >> s;
    string st = t + '#' + s;
    vector<int> p = prefix_function(st);
    int cnt = 0;
    for(int i = 0; i < st.size(); i++) if(p[i] == t.size()) cnt++;
    (cnt >= n) ? cout << "YES" : cout << "NO"; 
}