#include<bits/stdc++.h>

using namespace std;

long unsigned typedef int long ull;

bool search(ull a[], int l, int r, ull x){
    if(l > r) return false;
    int mid = l + (r - l)/2;
    if(a[mid] == x) return true;
    else if(a[mid] > x) return search(a, l, mid - 1, x);
    else return search(a, mid + 1, r, x);
}

int main(){
    ull m, n;
    cin >> m >> n;
    ull a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        ull num = m - a[i];
        if(num < 0) continue;
        if(search(a, 0, n-1, num)){
            cout << a[i] << " " << num;
            return 0;
        }
    }
}

