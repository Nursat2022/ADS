#include<bits/stdc++.h>

using namespace std;

int res(vector<int> v, int x){
    for(int i = v.size()-1; i >= 0; i--){
        if(v[i] <= x) return v[i];
    }
    return -1;
}

int main(){
    int n; cin >> n;
    queue<int> q;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cout << res(v, x) << " ";
        v.push_back(x);
    }
}