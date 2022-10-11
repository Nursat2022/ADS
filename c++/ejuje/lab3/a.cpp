#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int a[t];
    for(int i = 0; i < t; i++) cin >> a[i];
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }
    
    for(int i = 0; i < t; i++){

        bool ok = false;

        for(int j = 0; j < n; j++){

            int l = 0, r = m - 1;

            for(int k = 0; k < m; k++){
                if(j % 2 == 0){
                    if(a[i] <= arr[j][0] && a[i] >= arr[j][m-1]){
                        while(l <= r){
                            int mid = (l + r)/2;
                            if(arr[j][mid] == a[i]){
                                cout << j << " " << mid << "\n";
                                ok = true;
                                break;
                            }
                            else if(arr[j][mid] > a[i]) l = mid + 1;
                            else r = mid - 1;
                        }     
                        break;           
                    }
                }

                else{
                    if(a[i] <= arr[j][m-1] && a[i] >= arr[j][0]){
                        while(l <= r){
                            int mid = (l + r)/2;
                            if(arr[j][mid] == a[i]){
                                cout << j << " " << mid << "\n";
                                ok = true;
                                break;
                            }
                            else if(arr[j][mid] > a[i]) r = mid - 1;
                            else l = mid + 1;
                        }
                    }
                    break;
                }
            }
        }
        if(!ok) cout << -1 << "\n";
    }
}