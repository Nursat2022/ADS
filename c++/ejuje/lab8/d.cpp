#include<iostream>
#include<map>
#include<vector>

using namespace std;

int mod = 1e9 + 7;
int X = 26;
int mx = 0;

long long hashcode(string &s){
    long long hash = 0, pow = 1, p = 26;
    for(int i = 0; i < s.size(); i++){
        long long curhash = (s[i] - 'a' + 1) * pow % mod;
        hash = (hash + curhash) % mod;
        pow = (pow * p) % mod;
    }
    return hash;
}

vector<long long> getPrefixHashes(string &s) {
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % mod;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % mod;
        }
        curX = (curX * X) % mod;
    }
    return hashes;
}

void rabinKarp(string &s, pair<string, int> &p) {
    string t = p.first;
    if (t.size() > s.size()) return;
    long long smallHash = hashcode(t);
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i + t.size() - 1 < s.size(); i++) {
        long long hash = hashes[i + t.size() - 1];
        if (i != 0) hash -= hashes[i - 1];
        if (hash < 0) hash += mod;
        if (i != 0) smallHash = (smallHash * X) % mod;
        if (smallHash == hash){
            p.second++;
            if(p.second > mx) mx = p.second;
        }
    }
}

int main(){
    int n;

    while(cin >> n && n != 0){
        vector<pair<string, int> > v;
        for(int i = 0; i < n; i++){
            string t; cin >> t;
            v.push_back(make_pair(t, 0));
        }
        string s; cin >> s;
        for(int i = 0; i < v.size(); i++){
            rabinKarp(s, v[i]);
        }
        cout << mx << "\n";
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == mx) cout << v[i].first << "\n";
        }
        mx = 0;
    }
}