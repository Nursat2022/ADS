#include<iostream>

using namespace std;

class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        a[0] = 1e9+346;
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

    void sift_up(int i){
        while(i > 1 && a[parent(i)] > a[i]){
            swap(a[i], a[parent(i)]);
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

    void extractMin(){
        int ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
    }

    int getmin(){
        return a[1];
    }

    int getsize(){
        return size;
    }
};

int main(){
    Heap h;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        h.insert(x);
        while(h.getmin() < x - 3000) h.extractMin();
        cout << h.getsize() << " ";
    }
}