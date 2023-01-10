#include<iostream>
#include<vector>

using namespace std;

int mx = 105;
int a[106][106];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)cin >> a[i][j];
    }
    cout << endl;
    vector<int> colors(n);
    for(int i = 0; i < n; i++) cin >> colors[i];

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1 && colors[i - 1] != colors[j - 1]) cnt++;
        }
    }
    cout << cnt / 2;
}