#include<bits/stdc++.h>

using namespace std;

int getCount(int a, int b, int c, int num){
    int cnt = 0;
    cnt += num / a;
    cnt += num / b;
    cnt += num / c;
    return cnt;
}

int main(){
    int n; cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    long long l = -1, r = 1e18+123;
    while(l + 1 < r){
        int mid = l + (r - l)/2;
        if(getCount(a, b, c, mid) >= n) r = mid;
        else l = mid;
    }
    cout << r;
}