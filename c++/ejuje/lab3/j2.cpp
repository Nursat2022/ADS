#include <bits/stdc++.h> 
 
using namespace std; 
 
long long getTimeToWork(vector<long long> &bags, long long sz) { 
    long long res = 0; 
    for(auto i : bags) { 
        res += i/sz; 
        if(i%sz) 
            res++; 
    } 
    return res; 
} 
 
int main() { 
 
    long long n, h; 
    cin >> n >> h; 
    vector<long long> bags(n); 
    for(auto &i: bags) 
        cin >> i; 
    long long l = 0, r = 1e18+123; 
    while(l + 1 < r) { 
        long long mid = (l+r)/2; 
        long long timeToWork = getTimeToWork(bags, mid); 
        if(timeToWork <= h) 
            r = mid; 
        else 
            l = mid; 
    } 
    cout << r; 
    return 0; 
}