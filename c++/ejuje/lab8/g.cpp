#include<iostream>
#include<map>
#include<vector>

using namespace std;

int mod = 1e9 + 7;
int X = 26;
int mx = 0;

long long hashcode(string &s){
    long long hash = 0, pow = 1;
    for(int i = 0; i < s.size(); i++){
        long long curhash = (s[i] - 'a' + 1) * pow % mod;
        hash = (hash + curhash) % mod;
        pow = (pow * X) % mod;
    }
    return hash;
}

vector<long long> getHashes(string &s) {
    long long curX = 1;
    vector<long long> hashes(s.size());
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % mod;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % mod;
        }
        curX = (curX * X) % mod;
    }
    return hashes;
}

long long rabinKarp(string &s, string &t, vector<long long> &hashes) {
    long long cnt = 0;
    long long smallHash = hashcode(t);
    for (int i = 0; i + t.size() - 1 < s.size(); i++) {
        long long hash = hashes[i + t.size() - 1];
        if (i != 0) hash -= hashes[i - 1];
        if (hash < 0) hash += mod;
        if (i != 0) smallHash = (smallHash * X) % mod;
        if (smallHash == hash){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string s; cin >> s;   
    vector<long long> hashes = getHashes(s);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        string tmp = "";
        for(int j = l-1; j <= r-1; j++) tmp += s[j];
        cout << rabinKarp(s, tmp, hashes) << "\n";
    }
}