#include<bits/stdc++.h>

using namespace std;

long long getCount(vector<int> &v, long long num){
    long long sum = 0, res = 0;
    for(auto i : v){
        if(i > num) return 1e18+123;
        else if(sum + i > num){
            res++;
            sum = i;
        }
        else sum += i;
    }
    if(sum) res++;
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    long long l = -1, r = 1e18+123;
    while(l + 1 < r){
        long long mid = l + (r - l)/2;
        if(getCount(v, mid) <= k) r = mid;
        else l = mid;
    }
    cout << r;
}