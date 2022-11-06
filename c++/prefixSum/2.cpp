#include<bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s){
    int n = (int) s.length();
    vector<int> pi(n);
    for(auto i : pi) cout << i << " ";
    cout << endl;
    for(int i = 1;  i < n; i++){
        int j = pi[i-1];
        cout << i << " " << j << endl;
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string s; cin >> s;
    vector<int> p = prefix_function(s);
    for(auto i : p) cout << i << " ";
}