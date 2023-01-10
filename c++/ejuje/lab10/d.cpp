#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 5005;
vector<int> g[MAXN];
vector<long long> d(MAXN);
bool atLeastOneRed = false;
int n, m, q;
int state[MAXN];
int RED = 1;

void bfs(int v){
    state[v] = RED;
    queue<int> qu;
    qu.push(v);
    d[v] = 0;
    while(!qu.empty()){
        int v = qu.front();
        qu.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(d[to] > d[v] + 1){
                d[to] = d[v] + 1;
                qu.push(to);
            }
        }
    }
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) d[i] = 1e9;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < q; i++){
        int query, num;
        cin >> query >> num;
        if(query == 1){
            if(state[num] != RED) bfs(num);
        }
        else d[num] == 1e9 ? cout << -1 << "\n" : cout << d[num] << "\n";
    }
} 