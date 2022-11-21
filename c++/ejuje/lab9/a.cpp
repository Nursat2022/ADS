#include<iostream>
#include<vector>
#include<string>
#define ll long long

using namespace std;

vector<ll> prefix_function(string &s){
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

bool kmp(string &s, string &t){
    string st = t + '#' + s;
    int cnt = 0;
    vector<ll> p = prefix_function(st);
    for(int i = 0; i < st.size(); i++){
        if(p[i] == t.size()) cnt++;
    }
    return cnt;
}

int main(){
    string a, b;
    cin >> a >> b;
    int l = 0, r = 100000;

   while(l + 1 < r){
        int mid = l + (r - l)/2;
        bool ok = true;
        string t = a;
        for(int i = 1; i <= mid; i++){
            t += a;
        }
        int num =  kmp(t, b);
        if(num >= 2) r = mid; 
        else if(num == 1){
            cout << t.size() << " " << a.size() << "\n";
            cout << t.size() / a.size();
            return 0;
        }
        else l = mid;
   }
    cout << -1;
}