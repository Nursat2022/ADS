#include<iostream>
#include<vector>
#include<map>

using namespace std;

long long mod = 1e9 + 7;

vector<long long> h(string &s, string &t){
    int n = s.size(), m = t.size();
    vector<long long> mpow(n);
    vector<long long> ans;
    long long p = 5, ht = 0;
    mpow[0] = 1;
    for(int i = 1; i < n; i++) mpow[i] = (mpow[i - 1] * p) % mod;
    for(int i = 0; i < m; i++){
        ht = (ht + (t[i] - 'a' + 1) * mpow[i] % mod) % mod; 
    }
    vector<long long> hashcode(n);
    for(int i = 0; i < n; i++){
        hashcode[i] = (s[i] - 'a' + 1) * mpow[i] % mod;
        if(i > 0) hashcode[i] = (hashcode[i] + hashcode[i - 1]) % mod;
    }
    
    for(int i = 0; i + m - 1 < n; i++){
        long long num = hashcode[i + m - 1];
        if(i > 0) num -= hashcode[i - 1];
        if(num < 0) num += mod;
        if((ht * mpow[i]) % mod == num) ans.push_back(i);
    }
    return ans;
}

int main(){
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    map<int, int> mp;

    vector<long long> v1 = h(s1, t);
    vector<long long> v2 = h(s2, t);
    int cnt = 0;
    for(int i = 0; i < v1.size(); i++){
        mp[v1[i]]++;
    }
    for(int i = 0; i < v2.size(); i++){
        if(mp[v2[i]]) cnt++;
    }
    cout << cnt;
}