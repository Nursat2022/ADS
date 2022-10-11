#include<bits/stdc++.h>

using namespace std;  

bool isprime(int n){
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int nthPrime(int n, int ind, int num){
    if(isprime(num)){
        if(isprime(ind)) n--;
        ind++;
    }
    if(n == 0) return num;
    return nthPrime(n, ind, ++num);
}

int main(){
    int n; cin >> n;
    cout << nthPrime(n, 1, 2);
}