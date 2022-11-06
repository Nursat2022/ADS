#include <bits/stdc++.h> 
using namespace std; 
  
pair<int, int> func(int n){
    vector<bool> prime(n + 1, true); 
    vector<int> v1; 
    vector<int> v2; 
  
    for (int i = 2; i * i <= n; i++) { 
        if (prime[i]) { 
            for (int j = i * i; j <= n; j += i) 
                prime[j] = false; 
        } 
    } 
 
    for (int i = 2; i <= n; i++){ 
        if(prime[i]){ 
            v1.push_back(i); 
            v2.push_back(i); 
        } 
    } 
    for(int i = 0; i < v1.size();i++){ 
        for(int j = 0; j < v1.size();j++){ 
            if(v1[i] + v2[j] == n){
                return {v1[i], v2[j]};
            }
        }
    } 
} 
 
int main(){ 
    int n; cin >> n; 
    pair<int, int> ans = func(n);
    cout << ans.first << " " << ans.second;
}