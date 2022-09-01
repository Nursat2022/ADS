#include<bits/stdc++.h>

using namespace std;

int mx(int a[], int n, int maxi, int i){
    if(i == n) return maxi;
    else if(a[i] > maxi) maxi = a[i];
    return mx(a, n, maxi, ++i);
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << mx(a, n, a[0], 0);
}