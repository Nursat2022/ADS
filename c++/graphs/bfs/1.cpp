#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 1000005;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> p(MAXN);
vector<int> d(MAXN);

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }
    int s, f;
    cin >> s >> f;
    queue<int> q;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    if(used[f]) cout << d[f];
    else cout << -1;
    // for(int i = 1; i <= n; i++) cout << d[i] << " ";
    // cout << endl;
    // for(int i = 1; i <= n; i++) cout << p[i] << " ";
}