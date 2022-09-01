#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int mx1 = -1, mx2 = -1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > mx1){
            mx2 = mx1;
            mx1 = x;
        }
        else if(x > mx2 && x < mx1){
            mx2 = x;
        }
    }    
    cout << mx2;
}