#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 5005;
vector <int> g[MAXN];
int state[MAXN];
stack <int> s;
vector <int> p; 

bool dfs(int v, int a, int b){
    state[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];

        if(v == a && b == to) continue;
        
        if(!state[to]) {
            if (dfs(to, a, b)) return true;
        } 
        else if (state[to] == 1) return true;
    }
    state[v] = 2;
    return false;
}

bool dfs2(int v){
    state[v] = 1;
    s.push(v);

    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if( !state[to] ){
            if (dfs2(to)) return true;
        } else if (state[to] == 1){
            while(s.top() != to){
                p.push_back(s.top());
                s.pop();
            }

            p.push_back(to);
            p.push_back(v);

            reverse(p.begin(), p.end());
            return true;
        }
    } 
    state[v] = 2;
    if (!s.empty()) s.pop();
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    bool ok = false;

    for (int i = 1; i <= n; i++) {
        if (!state[i]){
            ok = dfs2(i);
            if(ok) break;
        }
    }
    
    if(!ok){
        cout << "YES\n";
        return 0;
    }

    for (int i = 0; i < p.size() - 1; i++) {
        int u = p[i];
        int v = p[i + 1];
       
        for(int j = 1; j <= n; j++) state[j] = 0;

        ok = false;

        for(int j = 1; j <= n; j++){
            if (!state[j]) {
                ok |= dfs(j, u, v);
            }
        }
        if(!ok){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}