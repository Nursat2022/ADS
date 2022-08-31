#include<bits/stdc++.h>

using namespace std;

int main(){
    deque<int> d1, d2;
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        char z; int x;
        cin >> z;
        if(z == '+'){
            cin >> x;
            d1.push_back(x);
        }
        if(d1.size() > d2.size()){
            d2.push_back(d1.front());
            d1.pop_front();
        }
        if(z == '-'){
            cout << d2.front() << endl;
            d2.pop_front();
        }
        if(z == '*'){
            cin >> x;
            d1.push_front(x);
        }
    }
}