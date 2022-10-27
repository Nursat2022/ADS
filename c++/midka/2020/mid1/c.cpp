#include<bits/stdc++.h>

using namespace std;

int search(int a[], int l, int r, int x, bool ok){
    if(ok){
        while(l + 1 < r){
            int mid = l + (r - l)/2;
            if(a[mid] >= x) r = mid;
            else l = mid;
        }
        return r;
    }
    else{
        while(l + 1 < r){
            int mid = l + (r - l)/2;
            if(a[mid] <= x) l = mid;
            else r = mid;
        }
        return l;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l1, r1, l2, r2;
    while(m--){
        int ans = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        ans += search(a, 0, n, r1, false) - search(a, -1, n-1, l1, true) + 1;
        ans += search(a, 0, n, r2, false) - search(a, -1, n-1, l2, true) + 1;
        int mx = max(l1, l2), mn = min(r1, r2);
        if(mn > mx) ans -= search(a, 0, n, mn, false) - search(a, -1, n-1, mx, true) + 1;
        cout << ans << "\n";
    }
}