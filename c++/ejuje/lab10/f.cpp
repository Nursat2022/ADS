#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> d(MAXN);

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int s, f;
    cin >> s >> f;
    queue<int> q;
    q.push(s);
    used[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                // d[to] = d[v] + 1;
            }
        }
    }
    cout << endl;
    used[f] ? cout << "YES" : cout << "NO";
}