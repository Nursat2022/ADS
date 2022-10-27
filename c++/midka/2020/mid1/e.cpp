#include<bits/stdc++.h>

using namespace std;

bool isprime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int getCount(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!isprime(i)) cnt++;
    }
    return cnt;
}

int main(){
    int n; cin >> n;
    // long long l = -1, r = 1e18+123;
    // while(l + 1 < r){
    //     int mid = l + (r - l)/2;
    //     if(getCount(mid) <= )
    // }
    cout <<getCount(n);
}