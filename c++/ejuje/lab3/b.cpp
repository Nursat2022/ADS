#include<bits/stdc++.h>

using namespace std;

long long result(vector<long long> &v, long long num){
    long long sum = 0, ans = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > num) return 1e18+123;
        if(sum + v[i] > num){
            ans++;
            sum = v[i];
        }
        else sum += v[i];
    }
    if(sum) ans++;
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    long long l = 0, r = 1e18+123;
    while(l + 1 < r){
        long long mid = (l + r)/2;
        long long num = result(v, mid);
        if(num > k) l = mid;
        else r = mid;
    }     
    cout << r;
    
}