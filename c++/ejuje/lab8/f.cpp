#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

long long mod = 1e17 + 7;

long long hashcode(string &s, unordered_map<long long, int> &mp){
    long long pow = 1, p = 26;
    for(int i = 0; i < s.size(); i++){
        long long hash = 0;
        for(int j = i; j < s.size(); j++){
            long long curhash = (s[j] - 'a' + 1) * pow % mod;
            hash = (hash + curhash) % mod;
            if(!mp[hash]) mp[hash] = 1;
            pow = (pow * p) % mod;
        }
        pow = 1;
    }
    return mp.size();
}

int main(){
    string s; cin >> s;
    unordered_map<long long, int> mp;
    cout << hashcode(s, mp);
}