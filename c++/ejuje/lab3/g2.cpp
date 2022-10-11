#include <bits/stdc++.h> 
 
using namespace std; 
 
int main() { 
 
    int n, m; 
    cin >> n >> m; 
    vector<int> nums(n); 
    for(int i = 0 ; i < n; i++) { 
        cin >> nums[i]; 
        if(i) 
            nums[i] += nums[i-1]; 
    } 
 
    while(m--) { 
        int mistakeNum; 
        cin >> mistakeNum; 
        int l = -1, r = n-1; 
        while(l + 1 < r) { 
            int mid = (l+r)/2; 
            if(nums[mid] >= mistakeNum) 
                r = mid; 
            else 
                l = mid; 
        } 
        cout << r+1 << endl; 
    } 
 
    return 0; 
}