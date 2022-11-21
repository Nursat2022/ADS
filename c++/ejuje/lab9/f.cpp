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

vector<int> kmp(string &s, string &t){
    string st = t + '#' + s;
    vector<int> p = prefix_function(st);
    vector<int> ans;
    for(int i = 0; i < st.size(); i++){
        if(p[i] == t.size()) ans.push_back(i - 2  * t.size() + 1);
    }
    return ans;
}

int main(){
    string s, t;
    cin >> s >> t;
    vector<int> ans = kmp(s, t);
    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << " ";
}