#include <iostream>
#include<vector>

using namespace std;

vector<vector<int> > g;
vector<int> p;
vector <int> ans;
int cnt = 0;

int dsu(int v){
    return v == p[v] ? v : p[v] = dsu(p[v]);
}

bool dsu2(int a, int b){
    a = dsu(a);
    b = dsu(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    g.resize(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++) p.push_back(i);


    for(int i = n - 1; i >= 0; i--){
        ans.push_back(cnt);
        cnt++;
        for(int j = 0; j < g[i].size(); j++){
            int to = g[i][j];
            if(i < to){
                if(dsu2(i, to)) cnt--;
            }
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << "\n";
}