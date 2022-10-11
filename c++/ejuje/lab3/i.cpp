#include<bits/stdc++.h>

using namespace std;

bool binary_search(int a[], int x, int l, int r){
    if(l > r) return false;
    int mid = (r + l)/2;
    if(a[mid] == x) return true;
    else if(x < a[mid]) return binary_search(a, x, l, mid-1);
    else return binary_search(a, x, mid+1, r);
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int k; cin >> k;
    if(binary_search(a, k, 0, n-1)) cout << "Yes";
    else cout << "No";
}