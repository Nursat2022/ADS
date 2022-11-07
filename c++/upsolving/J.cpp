#include<bits/stdc++.h>

using namespace std;

bool search(long long a[], int l, int r, long long x){
    if(l > r) return false;
    long long mid = l + (r - l)/2;
    if(a[mid] == x) return true;
    else if(a[mid] > x) return search(a, l, mid - 1, x);
    else return search(a, mid + 1, r, x);
}

int main(){
    long long m, n;
    cin >> m >> n;
    long long a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        long long num = m - a[i];
        if(search(a, i+1, n-1, num)){
            cout << a[i] << " " << num;
            return 0;
        }
    }
}