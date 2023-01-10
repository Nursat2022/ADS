#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int, int> > g[100000];
bool used[100000];

int main(){
    int n; cin >> n;
    int a[510];

    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    for(int i = 0; i < n; i++){
        g[0].push_back(make_pair(i, a[i] + a[0]));
        g[i].push_back(make_pair(0, a[i] + a[0]));
    }

    int weight = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >,  greater<pair<int, int> > > q;

    q.push(make_pair(0, 1));

    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();

        int mst = p.first, v = p.second;

        if(used[v]) continue;

        used[v] = true;

        weight += mst; 
        
        for(pair<int, int> e : g[v]){
            int u = e.first, length = e.second;
            if(!used[u]){
                q.push(make_pair(length, u));
            }
        }
    }
    cout << weight << endl;
}