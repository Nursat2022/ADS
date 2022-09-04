#include<bits/stdc++.h>

using namespace std;

class Heap{
    int a[100005];
    int size;
public:
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

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    int sift_up(int i){
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i;
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild = left(i);
        if(l > size){
            cout << i << endl;
            return;
        }
        if(r <= size){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
        }
        else cout << i << endl;
    }

    int extractMax(){
        int ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    void increase(int pos, int val){
        a[pos] += val;
        cout << sift_up(pos) << endl;
    }

    void decrease(int pos, int val){
        a[pos] -= val;
        sift_down(pos);
    }

    void change(int pos, int val){
        if(val > a[pos]){
            a[pos] = val;
            cout << sift_up(pos) << endl;
        }
        else if(val < a[pos]){
            a[pos] = val;
            sift_down(pos);
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    // Heap heap;
    // int n; cin >> n;
    // for(int i = 0; i < n; i++){
    //     int x; cin >> x;
    //     heap.insert(x);
    // }
    // heap.print();
    // heap.increase(3, 10);
    // heap.decrease(2, 25);
    // heap.print();
    // heap.change(2, 100);
    // heap.print();

    Heap h;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        h.insert(x);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int pos, val;
        cin >> pos >> val;
        h.decrease(pos, val);
    }
    h.print();
}