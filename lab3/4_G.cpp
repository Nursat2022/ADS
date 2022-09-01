#include<bits/stdc++.h>

using namespace std;

int binSearch1(int a[], int l, int r, int x){
    while(l <= r){
        int mid = l + ((r - l) / 2);
        if(a[mid] == x) return mid;
        else if(x < a[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

string binSearch2(int a[], int l, int r, int x){
    while(l <= r){
        int mid = l + ((r - l) / 2);
        if(a[mid] == x) return "YES";
        else if(x < a[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return "NO";
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        // if(binSearch1(a, 0, n - 1, x) == -1) cout << "NO" << endl;
        // else cout << "YES" << endl;
        cout << binSearch2(a, 0, n - 1, x) << endl;
    }
}