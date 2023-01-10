#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std; 

const int MAXN = 1e9; 
vector<pair<int,int> > g[200005]; 
vector<int> d(2e5+5, MAXN); 
int n, m; 

int deikstra(int s, int end){ 
    d.clear(); 
    for(int i = 0;i < 200005; i++) d[i] = MAXN;
    d[s] = 0; 
    set< pair<int,int> > q; 
    q.insert(make_pair(d[s], s)); 
    while(!q.empty()){ 
        int v = q.begin() -> second; 
        q.erase(q.begin()); 
        for(int j = 0; j < g[v].size(); j++){ 
            int to = g[v][j].first; 
            int len = g[v][j].second; 
            if(d[v] + len < d[to]){ 
                q.erase(make_pair(d[to], to)); 
                d[to] = d[v] + len; 
                q.insert(make_pair(d[to], to)); 
            } 
        } 
    } 
    return d[end]; 
} 

int main(){ 
    cin >> n >> m; 
    for (int i = 0; i < m; i++){ 
        int a, b, c; 
        cin >> a >> b >> c; 
        g[a].push_back(make_pair(b,c)); 
        g[b].push_back(make_pair(a,c)); 
    } 
    int q, w, e, r, a, b;
    cin >> q >> w >> e >> r;  

    a = deikstra(q,w) + deikstra(w,e) + deikstra(e,r); 
    b = deikstra(q,e) + deikstra(e,w) + deikstra(w,r) ; 

    min(a, b) <= MAXN ? cout << min(a, b) : cout << -1;
}