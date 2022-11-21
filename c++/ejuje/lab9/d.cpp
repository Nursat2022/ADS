#include<iostream>
#include<vector>
#include<string>
#define ll long long
using namespace std;

vector<ll> prefix_function(string s){
    int n = (int) s.length();
    vector<ll> pi(n);
    for(int i = 1;  i < n; i++){
        ll j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string s;
    int n;
    cin >> s >> n;
    vector<pair<pair<string, string>, ll> > str;
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        string tlow = t;
        tlow[0] = tolower(tlow[0]);
        str.push_back(make_pair(make_pair(t, tlow), 0));
    }
    ll mx = 0;
    for(int i = 0; i < str.size(); i++){
        vector<ll> v = prefix_function(str[i].first.second + '#' + s);
        if(v[v.size()-1] > mx) mx = v[v.size()-1];
        str[i].second = v[v.size()-1];
    }
    vector<string> ans;
    
    for(int i = 0; i < str.size(); i++){
        if(str[i].second == mx) ans.push_back(str[i].first.first);
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
}