#include <bits/stdc++.h> 
using namespace std; 
  
void SieveOfEratosthenes(int n) 
{ 
 
    bool prime[n + 1]; 
    memset(prime, true, sizeof(prime)); 
    vector<int> v1; 
    vector<int> v; 
    int cnt; 
  
    for (int p = 2; p * p <= n; p++) { 
        if (prime[p] == true) { 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
 
    } 
 
    for (int p = 2; p <= n; p++){ 
        if(prime[p])  { 
            v.push_back(p); 
            v1.push_back(p); 
        } 
    } 
    for(int i = 0; i < v.size();i++){ 
        for(int j = 0; j < v1.size();j++){ 
         
        if(v[i] + v1[j] == n)  
        { 
            cout  << v[i] << " " << v[j]; 
           return; 
           } 
    } 
} 
} 
 
int main() 
{ 
    int n; 
    cin >> n; 
    SieveOfEratosthenes(n); 
    return 0; 
}