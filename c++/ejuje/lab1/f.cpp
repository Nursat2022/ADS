#include<bits/stdc++.h>

using namespace std;

bool isprime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int nthPrime(int n, int num){
    if(isprime(num)) n--;
    if(n == 0) return num;
    return nthPrime(n, ++num);
}

int main(){
    int n; cin >> n;
    cout << nthPrime(n, 2);
}