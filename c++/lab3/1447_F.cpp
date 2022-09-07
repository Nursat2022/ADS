#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    int mx = -1, mn = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > mx) mx = a[i];
        if(mn == -1) mn = a[i];
        else if(a[i] < mn) mn = a[i];
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] == mx) a[i] = mn;
        cout << a[i] << " ";
    }
}