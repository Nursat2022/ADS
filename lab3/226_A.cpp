#include<bits/stdc++.h>

using namespace std;

void linsearch(int a[], int n, int k, int i){
    if(i == n) return;
    else if(a[i] == k) cout << i + 1 << " ";
    return linsearch(a, n, k, ++i);

}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int k; cin >> k;
    linsearch(a, n, k, 0);
}