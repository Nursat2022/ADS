// #include<bits/stdc++.h>

// using namespace std;

// int binary_recur(int a[], int n, int x, int l, int r){
//     int mid = l + ((r - l)/2);
//     if(x <= a[mid]){
//         if(mid == 0) return 1;
//         if(x > a[mid-1]) return mid + 1;
//         return binary_recur(a, n, x, l, mid-1);
//     }
//     else if(x > a[mid]){
//         if(x <= a[mid+1]) return mid+2;
//         return binary_recur(a, n, x, mid+1, r);
//     }
// }

// int main(){
//     int n, m;
//     cin >> n >> m;
//     int a[n], a1[n];
//     int num = 0;
//     for(int i = 0; i < n; i++){
//         int x; cin >> x;
//         a[i] = num + x;
//         num += x;
//     }

//     for(int i = 0; i < n; i++) cout << a[i] << " ";
//     cout << endl;

//     for(int i = 0; i < m; i++) cin >> a1[i];
    
//     for(int i = 0; i < m; i++){
//         int l = 0, r = n - 1;
//         while(l <= r){
//             int mid = l + ((r - l)/2);
//             if(a1[i] == a[mid]){
//                 cout << mid + 1 << endl;
//                 break;
//             }
//             else if(a1[i] < a[mid]){
//                 if(mid == 0){
//                     cout << 1 << endl;
//                     break;
//                 }
//                 else if(a1[i] > a[mid-1]){
//                     cout << mid + 1 << endl;
//                     break;
//                 }
//                 r = mid;
//             }
//             else if(a1[i] > a[mid]){
//                 if(a1[i] <= a[mid + 1]){
//                     cout << mid + 2 << endl;
//                     break;
//                 }
//                 l = mid;
//             }
//         }
//     }

// }

#include<bits/stdc++.h>

using namespace std;

int binary_recur(int a[], int n, int x, int l, int r){
    int mid = (l + r)/2;
    if(x <= a[mid]){
        if(mid == 0) return 1;
        if(x > a[mid-1]){
            return mid + 1;
        }
        return binary_recur(a, n, x, l, mid-1);
    }
    else if(x > a[mid]){
        if(x <= a[mid+1]) return mid+2;
        return binary_recur(a, n, x, mid+1, r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], a1[m];
    int num = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = num + x;
        num += x;
    }

    for(int i = 0; i < m; i++) cin >> a1[i];
    
    for(int i = 0; i < m; i++){
        cout << binary_recur(a, n, a1[i], 0, n-1) << "\n";
    }

}
