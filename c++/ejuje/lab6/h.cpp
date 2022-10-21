#include<bits/stdc++.h>

using namespace std;

int partition(char a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(char a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int index(char a[], int l, int r, char k){
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(a[mid] <= k){
            l = mid;
        }
        else r = mid;
    }
    return l;
}

int main(){
    int n; cin >> n;
    char a[n+1];
    for(int i = 0; i < n; i++) cin >> a[i];
    char k; cin >> k;
    a[n] = k;
    quickSort(a, 0, n);
    n++;
    int ind = index(a, 0, n, k)+1;
    (ind == n) ? cout << a[0] : cout << a[ind];
}