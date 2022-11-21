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
    cin >> s >> t;
    vector<int> v = prefix_function(s + '#' + t + t);
    for(int i = 0; i <v.size(); i++){
        if(v[i] == s.size()){
            cout << i - 2 * s.size();
            return 0;
        }
    }
    cout << -1;
}