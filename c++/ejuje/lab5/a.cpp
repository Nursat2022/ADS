#include<bits/stdc++.h>

using namespace std;

class Heap{
    long long a[200005];
public:
    int size;
    Heap(){
        a[0] = INT_MAX;
        size = 0;
    }

    int parent(int i){
        return i / 2;
    }

    int left(int i){
        return i * 2;
    }

    int right(int i){
        return i * 2 + 1;
    }

    void insert(long long val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] > a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        if(l > size) return;
        int minChild = l;
        if(r <= size){
            if(a[r] < a[l]) minChild = r;
        }
        if(a[i] > a[minChild]){
            swap(a[i], a[minChild]);
            sift_down(minChild);
        }
    }

    int extractMin(){
        int ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    Heap h;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        h.insert(x);
    }

    long long cost = 0;
    while(h.size > 1){
        int mn = h.extractMin();
        int smn = h.extractMin();
        h.insert(mn + smn);
        cost += mn + smn;
    }
    cout << cost;
}