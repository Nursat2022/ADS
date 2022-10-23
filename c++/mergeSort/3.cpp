#include<bits/stdc++.h>

using namespace std;

void MergeOne(int a[], int l, int mid, int r){
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int b[r + 1];
    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            b[k] = a[i];
            k++; i++;
        }
        else{
            b[k] = a[j];
            k++; j++;
        }
    }

    for(; i <= mid; i++){
        b[k] = a[i];
        k++;
    }

    for(; j <= r; j++){
        b[k] = a[j];
        k++;
    }

    for(i = l; i <= r; i++){
        a[i] = b[i];
    }
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int mid = (l + r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        MergeOne(a, l, mid, r);
    }
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n-1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    
}