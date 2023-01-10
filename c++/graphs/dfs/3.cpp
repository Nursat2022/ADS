// #include<iostream>
// #include<vector>

// using namespace std;

// const int MAXN = 105;
// int NEW = 0;
// int DURING = 1;
// int VISITED = 2;

// void dfs(int v){
//     if(state[v] == DURING){
//         cout << "cycle";
//         exit(0);
//     }
//     if(state[v] == VISITED) return;
//     state[v] = DURING;
//     for(int i = 0; i < g[v].size(); i++){
//         int to = g[v][i];
//         dfs(to);
//     }
//     used[v] = VISITED;
// }

// int main(){
//     int n, m;
// }

#include<iostream>
#include<vector>

using namespace std;

int NEW = 0;
int DURING = 1;
int VISITED = 2;
const int MAXN = 1000005;
vector<int> g[MAXN];
int state[MAXN];

void dfs(int v){
    // cout << v << " ";
    if(state[v] == DURING){
        cout << "Cycle";
        exit(0);
    }
    if(state[v] == VISITED) return;
    state[v] = DURING;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
    state[v] = VISITED;
    // cout << v << " ";
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
        if(state[i] == NEW) dfs(i);
    }
    cout << "Graph is acyclic";
}

/*

*/