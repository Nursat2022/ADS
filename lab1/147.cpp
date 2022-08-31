#include<bits/stdc++.h>

using namespace std;

int gcd(int mn, int mx){
    if(mx % mn == 0) return mn;
    return gcd(mx % mn, mn);
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << gcd(min(a, b), max(a, b));
}