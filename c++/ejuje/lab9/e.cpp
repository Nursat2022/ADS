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
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; int num;
        cin >> s >> num;
        vector<int> pref = prefix_function(s);
        cout << s.size() + (s.size() - pref[pref.size()-1]) * (num - 1) << "\n";
    }
}