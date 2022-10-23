#include<bits/stdc++.h>

using namespace std;

void mergeSort(int a[], int b[], int c[], int n, int m){
    int i, j, k;
    i = j = k = 0;
    // int c[n + m];
    while(i < n && j < m){
        if(a[i] < b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }

    for(; i < n; i++){
        c[k] = a[i];
        k++;
    }

    for(; j < m; j++){
        c[k] = b[j];
        k++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m], c[n + m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    mergeSort(a, b, c, n, m);
    for(int i = 0; i < n + m; i++){
        cout << c[i] << " ";
    }
}