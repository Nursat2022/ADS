#include<bits/stdc++.h>

using namespace std;

int gcd(long long mx, long long mn){

    if(mx % mn == 0) return mn;   
    
    return gcd(mn, mx % mn);
}

int lcm(long long a, long long b){
    return (a * b)/gcd(max(a, b), min(a, b));
}

int main(){
    long long a, b;
    cin >> a >> b;
    cout << lcm(a, b);
}