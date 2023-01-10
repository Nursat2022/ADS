#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN];
int state[MAXN];
int NEW = 0;
int VISITED = 2;
int DURING = 1;
vector<int> res;
vector<int> p(MAXN, -1);

void dfs(int v){
    if(state[v] == DURING){
        cout << "Impossible\n";
        exit(0);
    }
    if(state[v] == VISITED) return;
    state[v] = DURING;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
    res.push_back(v);
    state[v] = VISITED;
}

int main(){
    int n, m;
    cin >> n >> m;  
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        p[v] = u;
    }

    for(int i = 1; i <= n; i++){
        if(state[i] == NEW) dfs(i);
    }

    cout << "Possible\n";
    for(int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
}
