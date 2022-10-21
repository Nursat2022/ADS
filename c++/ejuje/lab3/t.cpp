#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int k; cin >> k;
    long long l = -1, r = n-1;
    while(l + 1 < r){
        int mid = l + ((r - l)/2);
        cout << l << " " << r << " " << mid << endl;
        if(a[mid] <= k) r = mid;
        else l = mid;
    }
    cout << r;
}