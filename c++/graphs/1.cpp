#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int a[105][105];

int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) cnt++;
        }
    }
    cout << cnt / 2;
}