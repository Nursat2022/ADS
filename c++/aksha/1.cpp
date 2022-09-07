#include<bits/stdc++.h>

using namespace std;

int gcd1(int mx, int mn){

    if(mx % mn == 0) return mn;   
    
    return gcd1(mn, mx % mn);
}

int gcd2(int a, int b){
    while(a > 0 && b > 0){
        if(a > b) a %= b;
        else b %= a;
    }
    if(a == 0) return b;
    return a;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd1(max(a, b), min(a, b));
}