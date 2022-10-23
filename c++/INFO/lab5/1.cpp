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

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void increase(int pos, int val){
        a[pos] += val;
        cout << sift_up(pos) << endl;
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
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int pos, val;
        cin >> pos >> val;
        h.increase(pos, val);
    }
    h.print();
}