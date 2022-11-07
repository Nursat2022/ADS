#include<bits/stdc++.h>

using namespace std;

int cnt = 0;

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

    void sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

void func(){
        for(int i = 1; i <= size; i++){
            if(left(i) > size) return;
            if(right(i) <= size){
                if(right(i) > left(i)) cnt++;
            }
        }
    }

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }
};

int main(){
    Heap h;
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        h.insert(x);
    }
    h.func();
    cout << cnt;
}