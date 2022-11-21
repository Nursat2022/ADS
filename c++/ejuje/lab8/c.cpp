#include<iostream>
#include<vector>

using namespace std;

int mod = 1e9 + 7;

// long long hashcode(string &s){
//     long long hash = 0, pow = 1, p = 26;
//     for(int i = 0; i < s.size(); i++){
//         long long curhash = (s[i] - 'a' + 1) * pow % mod;
//         hash = (hash + curhash) % mod;
//         pow = (pow * p) % mod;
//     }
//     return hash;
// }

// void h(string &s, string &t, vector<bool> &b){
//     int n = s.size(), m = t.size();
//     vector<long long> mpow(n);
//     vector<long long> ans;
//     long long p = 26, ht = 0;
//     mpow[0] = 1;
//     for(int i = 1; i < n; i++) mpow[i] = (mpow[i - 1] * p) % mod;
//     for(int i = 0; i < m; i++){
//         ht = (ht + (t[i] - 'a' + 1) * mpow[i] % mod) % mod; 
//     }
//     vector<long long> hashcode(n);
//     for(int i = 0; i < n; i++){
//         hashcode[i] = (s[i] - 'a' + 1) * mpow[i] % mod;
//         if(i > 0) hashcode[i] = (hashcode[i] + hashcode[i - 1]) % mod;
//     }
    
//     for(int i = 0; i + m - 1 < n; i++){
//         long long num = hashcode[i + m - 1];
//         if(i > 0) num -= hashcode[i - 1];
//         if(num < 0) num += mod;
//         if((ht * mpow[i]) % mod == num){
//             for(int j = i; j < i + t.size(); j++) b[j] = true;
//         }
//     }
// }

vector<long long> getHashes(string &s) {
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

void rabinKarp(string & s, string & t) {
    if (t.size() > s.size()) return;
    long long smallHash = getHash(t);
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0) hashDif -= hashes[i - 1];
        if (hashDif < 0) hashDif += mod;
        if (i != 0) smallHash = (smallHash * X) % mod;
        if (smallHash == hashDif){
            
        }
    }

}

int main(){
    string s; cin >> s;
    vector<bool> b(s.size(), false);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        h(s, t, b);
    }
    for(int i = 0; i < b.size(); i++){
        if(!b[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}