#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> prefix_function(string &s){
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

bool kmp(string &t, string &s){
    string st = s + '#' + t;
    // cdabcdab#abcdabcd
    int cnt = 0;
    vector<int> p = prefix_function(st);
    for(int i = 0; i < st.size(); i++){
        if(p[i] == s.size()) return true;
    }
    return false;
}

int main(){
    string t, s;
    cin >> t >> s;
    string t_copy = t;
    while(t.size() < s.size()) t += t_copy;
    if(!kmp(t, s)){
        t += t_copy;
        if(!kmp(t, s)) cout << -1;
        else cout << t.size()/t_copy.size();
    }
    else cout << t.size()/t_copy.size();
}

