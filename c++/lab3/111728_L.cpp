#include<bits/stdc++.h>

using namespace std;

int linsearch(int a[], int n, int k, int i){
    if(i == n) return -1;
    if(a[i] == k) return i;
    return linsearch(a, n, k, ++i);
}

int main(){
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    int first = 0, last = 0;
    for(int i = 0; i < n; i++) cin >> a1[i];
    
    for(int i = 0; i < m; i++){
        cin >> a2[i];
        first = 1 + linsearch(a1, n, a2[i], 0);
        reverse(a1, a1 + n);
        last = n - linsearch(a1, n, a2[i], 0);
        reverse(a1, a1 + n);
        if(first == 0) cout << first << endl;
        else cout << first << " " << last << endl;
    }
}