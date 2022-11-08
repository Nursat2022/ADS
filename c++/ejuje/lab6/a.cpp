// #include<bits/stdc++.h>

using namespace std;

bool isVowel(char z){
    if(z == 'a' || z == 'e' || z == 'i' || z == 'o' || z == 'u'){
        return true;
    }
    return false;
}

int partition(char a[], int low, int high){
    int pivot = a[high];
    int i = (low - 1);
    for(int j = low; j < high; j++){
        if(((isVowel(a[j]) && isVowel(pivot) || !isVowel(a[j]) && !isVowel(pivot)) && a[j] < pivot) || isVowel(a[j]) && !isVowel(pivot)){
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

int main(){
    int n; cin >> n;
    char a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    quickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i];
}