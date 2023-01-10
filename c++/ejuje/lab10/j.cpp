#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 1e5+5;
vector<int> g[MAXN];
vector<bool> used(MAXN);
int cnt = 0;

void dfs(int v){
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]){
            if(g[to].size() > g[v].size()) cnt++;
            dfs(to);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(!used[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}