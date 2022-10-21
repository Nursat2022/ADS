#include<bits/stdc++.h>

using namespace std;

int partition(int a[], int low, int high){
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

void quickSort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    map<int, int> mp;
    for(int i = 0; i < n; i++) cin >> a1[i];
    for(int i = 0; i < m; i++) cin >> a2[i];
    quickSort(a1, 0, n - 1);
    quickSort(a2, 0, m - 1);
    for(int i = 0 ; i < n; i++){
        mp[a1[i]]++;
    }
    for(int i = 0; i < m; i++){
        if(mp[a2[i]]){
            cout << a2[i] << " ";
            mp[a2[i]]--;
        }
    }
}