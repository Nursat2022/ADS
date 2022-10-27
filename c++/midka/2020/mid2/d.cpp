#include<bits/stdc++.h>

using namespace std;

class Heap{
    int a[100005];
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

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    int getMax(){ return a[1]; }

    int getLeft(){ return a[2]; }

    int getRight(){ return a[3]; };

    void sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
};

int main(){
    int n; cin >> n;
    Heap h;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        h.insert(num);
        if(i == 0 || i == 1){
            cout << -1 << "\n";
            continue;
        }
        int ans = h.getMax() * h.getLeft() * h.getRight();
        (ans < 0) ? cout << -1 : cout << ans;
        cout << "\n";
    }
}