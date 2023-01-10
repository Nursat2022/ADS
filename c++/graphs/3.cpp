#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1O5;
vector<int> g[MAXN];
bool used[MAXN];

void dfs(int v){
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cnt++;
            dfs(i);
        }
    }

}