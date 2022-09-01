#include<bits/stdc++.h>

using namespace std;

int ind(int a[], int index, int n, int maxi, int i){
    if(i == n) return index + 1;
    else if(a[i] > maxi){
        maxi = a[i];
        index = i;
    }
    return ind(a, index, n, maxi, ++i);
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << ind(a, 0, n, a[0], 0);
}