#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    deque<int> d;
    for(int i = 0; i < n; i++){
        d.clear();
        int num; cin >> num;
        for(int j = num; j > 0; j--){
            d.push_front(j);
            for(int k = 0; k < j; k++){
                d.push_front(d.back());
                d.pop_back();
            }
        }
        for(int i = 0; i < d.size(); i++) cout << d[i] << " ";
        cout << endl;
    }   
}