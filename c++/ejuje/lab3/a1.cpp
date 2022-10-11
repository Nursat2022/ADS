#include<bits/stdc++.h>

using namespace std;

pair<bool, int> binary_search(vector<int> &v, int ind, int x, int l, int r){
    if(l > r) return {false, -1};
    int mid = (l + r)/2;
    if(v[mid] == x) return {true, mid};
    else if(x < v[mid]){
        return (ind % 2 == 0) ? binary_search(v, ind, x, mid+1, r) : binary_search(v, ind, x, l, mid-1);
    }
    else {
        return (ind % 2 == 0) ? binary_search(v, ind, x, l, mid-1) : binary_search(v, ind, x, mid+1, r);
    }
}

pair<int, int> result(vector<vector<int>> &v, int x){
    int l = 0, r = v.size()-1;
    while(l <= r){
        int mid = (l + r)/2;
        if(mid % 2 == 0){
            if(x <= v[mid][0] && x >= v[mid][v[mid].size()-1]){
                pair<bool, int> p = binary_search(v[mid], mid, x, 0, v[mid].size()-1);
                if(p.first) return {mid, p.second};
                return {-1, -1};
            }
            else if(x > v[mid][0]) r = mid - 1;
            else if(x < v[mid][v[mid].size()-1]) l = mid + 1;
        }
        else{
            if(x <= v[mid][v[mid].size()-1] && x >= v[mid][0]){
                pair<bool, int> p = binary_search(v[mid], mid, x, 0, v[mid].size()-1);
                if(p.first) return {mid, p.second};
                return {-1, -1};
            }
            else if(x < v[mid][0]) l = mid + 1;
            else if(x > v[mid][v[mid].size()-1]) r = mid - 1;
        }
    }
    return {-1, -1};
}

int main(){
    int t; cin >> t;
    int a[t];
    for(int i = 0; i < t; i++) cin >> a[i];
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }

    for(int i = 0; i < t; i++){
        if(result(v, a[i]).first == -1) cout << -1 << "\n";
        else cout << result(v, a[i]).first << " " << result(v, a[i]).second << "\n";
    }    
}