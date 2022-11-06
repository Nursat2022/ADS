#include<bits/stdc++.h>

using namespace std;

bool func(int n){
    int cnt = 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) cnt++;
    }
    if(cnt == 1) return true;
    return false;
}

int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 4; i <= n; i++){
        if(func(i)) cnt++;
    }
    cout << cnt;
}