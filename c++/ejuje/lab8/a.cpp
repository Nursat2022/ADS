#include<iostream>
#include<vector>
#include<map>

using namespace std;

long long mod = 1e9 + 7;

long long hashcode(string &s){
    long long hash = 0, pow = 1, p = 11;
    for(int i = 0; i < s.size(); i++){
        long long curhash = (s[i] - 47) * pow % mod;
        hash = (hash + curhash) % mod;
        pow = (pow * p) % mod;
    }
    return hash;
}

int main(){
    int n; cin >> n;
    map<string, string> mp;
    vector<string> str;
    for(int i = 0; i < 2*n; i++){
        string s; cin >> s;
        mp[s] = to_string(hashcode(s));
        str.push_back(s);
    }
    int cnt = 0;

    for(int i = 0; i < str.size(); i++){
        string hash = to_string(hashcode(str[i]));
        if(mp.find(hash) != mp.end()){
            cout << "Hash of string \"" << str[i] << "\" is "<< hash << "\n";
            cnt++;
        }
        if(cnt == n) return 0;
    }
}