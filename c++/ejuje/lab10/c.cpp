#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 100005;
vector<long long> g[MAXN];
vector<long long> d(MAXN, 1e9);
vector<long long> p(MAXN);

int main(){
    int a, b;
    cin >> a >> b;
    queue<int> q;
    q.push(a);
    d[a] = 0;
    p[a] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int toX = v * 2;
        int toY = v - 1;
        if(toX > 0 && toY > 0 && toX <= MAXN && toY <= MAXN){
            if(d[toX] > d[v] + 1){
                d[toX] = d[v] + 1;
                q.push(toX);
                p[toX] = v;
            }
            if(d[toY] > d[v] + 1){
                d[toY] = d[v] + 1;
                q.push(toY);
                p[toY] = v;
            }
        }
    }   
    cout << d[b] << "\n";
    vector<int> v;
    for(int i = b; i != a; i = p[i]){
        v.push_back(i);
    }
    for(int i = v.size() -1; i >= 0; i--){
        cout << v[i] << " ";
    }
}


