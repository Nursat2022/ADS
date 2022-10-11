#include<bits/stdc++.h>

using namespace std;

void res(deque<int> d1, deque<int> d2, int cnt){
    while(!d1.empty() and !d2.empty() and cnt < 1000000){
        cnt++;
        int a = d1.front();
        int b = d2.front();
        d1.pop_front();
        d2.pop_front();
        if(a == 0 and b == 9){
            d1.push_back(a);
            d1.push_back(b);
        }
        else if(a == 9 and b == 0){
            d2.push_back(a);
            d2.push_back(b);
        }
        else if(a < b){
            d2.push_back(a);
            d2.push_back(b);
        }
        else if(a > b){
            d1.push_back(a);
            d1.push_back(b);
        }
    }

    if(d1.empty()) cout << "Nursik " << cnt;
    else if(d2.empty()) cout << "Boris " << cnt;
    else cout << "blin nichya";
}

void solve(){
    deque<int> d1(5);
    deque<int> d2(5);

    for(int i = 0; i < 5; i++) cin >> d1[i];
    for(int i = 0; i < 5; i++) cin >> d2[i];

    res(d1, d2, 0);
}

int main(){
    solve();
}