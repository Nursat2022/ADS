#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    for(int i = 0; i < q; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if(a[x-1][y-1] == 1 && a[x-1][z-1] == 1 && a[y-1][z-1] == 1) cout << "YES\n";
        else cout << "NO\n";
        // a[x-1][y-1] && a[x-1][z-1] && a[y-1][z-1] ? cout << "YES\n" : cout << "NO\n";
    }
}














