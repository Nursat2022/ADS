#include<bits/stdc++.h>

using namespace std;

struct Pasture{
    int x1, y1;
    int x2, y2;
};

long long getCount(vector<Pasture> &pastures, long long x){
    long long res = 0;
    for(auto &pasture : pastures){
        if(pasture.x1 <= x && pasture.y1 <= x && pasture.x2 <= x && pasture.y2 <= x){
            res++;
        }
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<Pasture> pastures(n);
    for(auto &pasture : pastures){
        cin >> pasture.x1 >> pasture.y1 >> pasture.x2 >> pasture.y2;
    }
    long long l = -1, r = 1e18+123;
    while(l + 1 < r){
        long long mid = l + (r - l)/2;
        if(getCount(pastures, mid) >= k) r = mid;
        else l = mid;
    }
    cout << r;
}