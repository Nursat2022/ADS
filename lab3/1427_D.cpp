#include<bits/stdc++.h>

using namespace std;

bool func(vector<vector<int> > v, int ind, int mn, int n){ 
    int mx = v[0][ind];
    for(int i = 0; i < n; i++){
        if(v[i][ind] > mx) mx = v[i][ind];
    }
    if(mx == mn) return true;
    return false;
}

int counter(vector<vector<int> > v, int m){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        int mn = -1000, ind = 0;
        for(int j = 0; j < v[i].size(); j++){
            if(mn == -1000){
                mn = v[i][j];
                ind = j;
            }
            else if(v[i][j] < mn){
                mn = v[i][j];
                ind = j;
            }
        }
        if(func(v, ind, mn, m))cnt++;
    }
    return cnt;
}

bool check(vector<vector<int> > v){
    int num = v[0][0];
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); i++){
            if(num != v[i][j]) return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }
    if(check(v)) cout << n * m;
    else cout << counter(v, m);
}