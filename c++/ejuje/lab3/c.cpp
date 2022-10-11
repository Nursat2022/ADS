#include<bits/stdc++.h>

using namespace std;

int search(int a[], int n, int l1, int r1, int l2, int r2){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if((a[i] >= l1 && a[i] <= r1) || (a[i] >= l2 && a[i] <= r2)) cnt++;
    }
    return cnt;
}

int main(){
    int n, m; 
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << search(a, n, l1, r1, l2, r2);
        cout << endl;
    }
}