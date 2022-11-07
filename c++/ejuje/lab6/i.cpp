#include<iostream>

using namespace std;

class Heap{
    char a[10000];
    int size;
public:
    Heap(){
        a[0] = 'z';
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

    void insert(char z){
        size++;
        a[size] = z;
        sift_up(size);
    }    

    void sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i, int sz){
        int l = left(i);
        int r = right(i);
        if(l > sz) return;
        int maxChild = l;
        if(r <= sz){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            heapify(maxChild, sz);
        }
    }

    void heapSort(){
        for(int i = size; i > 1; i--){
            swap(a[1], a[i]);
            heapify(1, i - 1);
        }
    }

    void print(){
        for(int i = 1; i <= size; i++) cout << a[i];
    }
};

int main(){
    Heap h;
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++){
        h.insert(s[i]);
    }
    h.heapSort();
    h.print();
}