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

    void sift_down(int i, int SZ){
        int l = left(i);
        int r = right(i);
        if(l > SZ){
            cout << i << " ";
            return;
        }
        int maxChild = l;
        if(r <= SZ){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild, SZ);
        }
        else{
            cout << i << " ";
        }
    }

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void increase(int pos, int val){
        a[pos] += val;
        cout << sift_up(pos) << endl;
    }

    void decrease(int pos, int val){
        a[pos] -= val;
        // sift_down(pos);
    }

    void extractMax(){
        for(int i = size; i > 1; i--){
            swap(a[1], a[i]);
            sift_down(1, i - 1);
            cout << a[i] << endl;
        }
    }

    void print(){
        for(int i = 1; i <= size; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main(){
    Heap h;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        h.insert(x);
    }
        h.extractMax();
}