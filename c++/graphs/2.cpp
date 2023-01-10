#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 105;

vector<int> g[MAXN];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // for(int i = 1; i <= n; i++){
    //     cout << "V = " << i << endl;
    //     for(int j = 0; j < g[i].size(); j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1; i <= n; i++){
        cout << g[i].size() << " ";
    }
}
/*
7 10
5 1
3 2
7 1
5 2
7 4
6 5
6 4
7 5
2 1
5 3
*/