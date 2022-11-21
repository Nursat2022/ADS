#include <iostream>
#include<vector>

using namespace std;
#define ll long long

ll MOD = 1e9 + 7;
ll X = 26;

vector<ll> getPrefix(string &s) {
    vector<ll> hashes(s.size());
    ll curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD; 
        if (i != 0) hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        curX = (curX * X) % MOD;
    }
    return hashes;
}

bool rabinKarp(string &s, ll smallhash, vector<ll> &hashes, int &l, int &r, vector<ll> &p_pow) {
    for(int i = 0; i < s.size() - r + 1; i++) {
        ll hashDif = hashes[i + r - 1], tmp = smallhash;
        if(i != 0) hashDif -= hashes[i - 1];
        if(hashDif < 0) hashDif += MOD;
        if(i < l){
            hashDif = (hashDif * p_pow[l - i]) % MOD;
        }
        else tmp = (tmp * p_pow[i - l]) % MOD;
        
        if(tmp == hashDif) return true;
    }
    return false;
}

int main() {
    int n; cin >> n;
    string mn = "";

    vector<pair<string, vector<ll> > > v;
    int mxsz = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        v.push_back(make_pair(s, getPrefix(s)));
            if(mn.size() == 0) mn = v[i].first;
            else {
                if(v[i].first.size() < mn.size()) mn = v[i].first;
            }
        if(v[i].first.size() > mxsz) mxsz = v[i].first.size();
    }

    vector<ll> p_pow(mxsz + 10);
    p_pow[0] = 1;
    for(int i = 1; i < mxsz; i++){
     p_pow[i] = p_pow[i - 1] * X % MOD;
    }

    vector<ll> minHash = getPrefix(mn);
    int mxn = 0, left = -1, right = -1;

    for(int i = 0; i < mn.size(); i++){
        int l = i, r = mn.size() - 1;
        while(l <= r){ 
            int mid = l + (r - l)/2;
            ll curHash = minHash[mid];
            if(i != 0) curHash -= minHash[i - 1];
            if(curHash < 0) curHash += MOD;
            int sz = mid - i + 1;
            bool ok = true;
            for(int j = 0; j < v.size(); j++){
                if(!rabinKarp(v[j].first, curHash, v[j].second, i, sz, p_pow)){
                    ok = false;
                    break;
                }
            }
            if(ok){
                if(sz > mxn){
                    right = sz;
                    left = i;
                    mxn = sz;
                }
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
    cout << mn.substr(left, right);
}