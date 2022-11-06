#include<bits/stdc++.h>

using namespace std;

long long pref[1000005];
void precalc(int a[], int n){
    pref[0] = a[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i - 1] + a[i];
    } 
}

long long query(int l, int r){
    if(l > 0){
        return pref[r] - pref[l - 1];
    }
    else{
        // if l == 0
        return pref[r];
    }
}

int main(){
    int n; cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    precalc(a, n);
    int m; cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        l--; 
        r--;
        cout << query(l, r) << " ";
    }

}