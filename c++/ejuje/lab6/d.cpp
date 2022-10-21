#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    if(a.first == b.first){
        if(a.second.second == b.second.second){
            if(a.second.first == b.second.first) return true;
            return a.second.first < b.second.first;
        }
        return a.second.second < b.second.second;
    }
    return a.first < b.first;
}

int partition(vector<pair<int, pair<int, int>>> &v, int low, int high){
    pair<int, pair<int, int>> pivot = v[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(cmp(v[j], pivot)){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quick_sort(vector<pair<int, pair<int, int>>> &v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);
        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}

int main(){
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> v;
    for(int i = 0; i < n; i++){
        int d, m, y;
        char z;
        cin >> d >> z >> m >> z >> y;
        v.push_back(make_pair(y, make_pair(d, m)));
    }
    quick_sort(v, 0, v.size()-1);
    for(auto i : v){
        (i.second.first < 10) ? cout << 0 << i.second.first << "-" : cout << i.second.first << "-";
        (i.second.second < 10) ? cout << 0 << i.second.second << "-" : cout << i.second.second <<"-";
        cout << i.first << "\n";
    }
}