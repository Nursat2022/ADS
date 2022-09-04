// #include<bits/stdc++.h>

// using namespace std;

// class Heap{
//     int a[100000];
//     int size;
// public:
//     Heap(){
//         a[0] = INT_MAX;
//         size = 0;
//     }

//     int parent(int i){
//         return i / 2;
//     }

//     int sift_up(int i){
//         while(i > 0 and a[parent(i)] < a[i]){
//             swap(a[parent(i)], a[i]);
//             i = parent(i);
//         }
//         return i;
//     }

//     int left(int i){
//         return i * 2;
//     }

//     int right(int i){
//         return i * 2 + 1;
//     }

//     void sift_down(int i){
//         if(size == 0){
//             cout << 0;
//             return;
//         }
//         int l = left(i);
//         int r = right(i);
//         if(l > size){
//             cout << i << " ";
//             return;
//         }
//         int maxChild = l;
//         if(r <= size){
//             if(a[r] > a[l]) maxChild = r;
//         }
//         if(a[i] < a[maxChild]){
//             swap(a[i], a[maxChild]);
//             sift_down(maxChild);
//         }
//         else{
//             cout << i << " ";
//         }
//     }

//     void insert(int val, int sz){
//         if(size >= sz){
//             cout << -1;
//             return;
//         } 
//         size++;
//         a[size] = val;
//         cout << sift_up(size) << endl;
//     }

//     void increase(int pos, int val){
//         a[pos] += val;
//         cout << sift_up(pos) << endl;
//     }

//     void decrease(int pos, int val){
//         a[pos] -= val;
//         // sift_down(pos);
//     }

//     int extractMax(){
//         if(size == 0) return -1;
//         int ans = a[1];
//         swap(a[1], a[size]);
//         size--;
//         sift_down(1);
//         return ans;
//     }

//     void print(){
//         for(int i = 1; i <= size; i++) cout << a[i] << " ";
//         cout << endl;
//     }
// };

// int main(){
//     Heap h;
//     int n, m;
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int x; cin >> x;
//         if(x == 1){
//             cout << h.extractMax() << endl;
//         }
//         else if(x == 2){
//             int a; cin >> a;
//             h.insert(a, n);
//         }
//     }
//     h.print();
// }



#include<bits/stdc++.h>

using namespace std;

class Heap{
    int a[100000];
    int size;
public:
    Heap(){
        a[0] = INT_MAX;
        size = 0;
    }

    int parent(int i){
        return i / 2;
    }

    int sift_up(int i){
        while(i > 0 and a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i;
    }

    int left(int i){
        return i * 2;
    }

    int right(int i){
        return i * 2 + 1;
    }

    void sift_down(int i){
        if(size == 0){
            cout << 0;
            return;
        }
        int l = left(i);
        int r = right(i);
        if(l > size){
            cout << i << " ";
            return;
        }
        int maxChild = l;
        if(r <= size){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
        }
        else{
            cout << i << " ";
        }
    }

    void insert(int val, int sz){
        if(size >= sz){
            cout << -1;
            return;
        } 
        size++;
        a[size] = val;
        cout << sift_up(size) << endl;
    }

    void increase(int pos, int val){
        a[pos] += val;
        cout << sift_up(pos) << endl;
    }

    void decrease(int pos, int val){
        a[pos] -= val;
        // sift_down(pos);
    }

    int extractMax(){
        if(size == 0) return -1;
        int ans = a[1];
        if(size > 1) swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    void print(){
        for(int i = 1; i <= size; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main(){
    Heap h;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(x == 1){
            cout << h.extractMax() << endl;
        }
        else if(x == 2){
            int a; cin >> a;
            h.insert(a, n);
        }
    }
    h.print();
}