#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> prefix_function(string s){
    int n = (int) s.length();
    vector<int> pi(n);
    // for(auto i : pi) cout << i << " ";
    // cout << endl;
    for(int i = 1;  i < n; i++){
        int j = pi[i-1];
        // cout << i << " " << j << endl;
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
    cin >> s >> t;
    string st = t + '#' + s;
    vector<int> p = prefix_function(st);
    for(int i = 0; i < st.size(); i++){
        if(p[i] == t.size()){
            cout << i - 2 * t.size() << " ";
        }
    }
}