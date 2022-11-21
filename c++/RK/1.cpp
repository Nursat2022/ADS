#include<iostream>
#include<vector>
#define ll long long

using namespace std;

int main(){
    string s, t; 
    cin >> s >> t;
    int n = s.size();
    vector<ll> p_pow(n);
    ll p = 5;
    p_pow[0] = 1;
    for(int i = 1; i < n; i++){
        p_pow[i] = p_pow[i-1] * p;
    }
    for(int i = 0; i < n; i++) cout << p_pow[i] << " ";
    cout << endl;
    ll ht = 0;
    for(int i = 0; i < t.size(); i++){
        ht += (t[i] - 'a' + 1) * p_pow[i]; // (t[i] - 96) chtoby a = 1, b = 2, c = 3 ...
    }
    cout << "ht = " << ht << endl;
    vector<ll> hs(n);
    for(int i = 0; i < n; i++){
        hs[i] = (s[i] - 'a' + 1) * p_pow[i];
        if(i > 0) hs[i] += hs[i - 1];
    }
    // for(auto i : hs) cout << i << " ";
    for(int i = 0; i < hs.size(); i++) cout << hs[i] << " ";
    cout << endl;
    for(int i = 0; i + t.size() - 1 < n; i++){
        ll cur = hs[i + t.size() - 1];
        if(i > 0) cur -= hs[i - 1];
        if(ht * p_pow[i] == cur) cout << i << " ";
    }
}