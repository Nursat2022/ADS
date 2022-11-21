#include<iostream>

using namespace std;

long long prev_hash = 0;
long long mod = 1e9 + 7;
long long X = 2;

char letter(long long hash, long long curX){
    hash -= prev_hash;
    hash /= curX;
    hash = (hash + 97) % mod;
    return hash + '0' - 48;
}

int main(){
    int n; cin >> n;
    long long curX = 1;
    for(int i = 0; i < n; i++){
        long long hash; cin >> hash;
        cout << letter(hash, curX);
        curX *= X;
        prev_hash = hash;
    }
}