#include <bits/stdc++.h> 
 
using namespace std; 
 
long long result(vector<int> &v, long long num) { 
    long long sum = 0, ans = 0; 
    for(auto i : v) { 
        if(i > num) return 1e18+123; 
        if(sum + i > num) { 
            ans++; 
            sum = i; 
        } 
        else sum += i;
    } 
    if(sum){
        cout << sum << endl;
        ans++;
    }
    return ans;
} 
 
int main() { 
    int n, k; 
    cin >> n >> k; 
    vector<int> v(n); 
    for(int i = 0; i < v.size(); i++) cin >> v[i];
    long long l = 0, r = 1e18+123; 
    while(l + 1 < r) { 
        long long mid = (l + r)/2; 
        long long num = result(v, mid); 
        if(num > k) l = mid; 
        else r = mid;
    } 
    cout << r; 
}