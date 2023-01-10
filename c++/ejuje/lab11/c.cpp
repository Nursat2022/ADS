#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int> > graph[1000];
bool used[1000];

int main(){
    int n, m, big, small;
    cin >> n >> m >> big >> small;
    int both = min(big, small);
    for(int i = 1; i <= m; i++){
        string asphalt;
        int a, b, c;
        cin >> asphalt >> a >> b >> c;
        if(asphalt == "big"){
            graph[a].push_back(make_pair(b, c * big));
            graph[b].push_back(make_pair(a, c * big));
        }
        else if(asphalt == "small"){
            graph[a].push_back(make_pair(b, c * small));
            graph[b].push_back(make_pair(a, c * small));
        }
        else{
            graph[a].push_back(make_pair(b, c * both));
            graph[b].push_back(make_pair(a, c * both));
        }
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
        
        for(pair<int, int> e : graph[v]){
            int u = e.first, length = e.second;
            if(!used[u]){
                q.push(make_pair(length, u));
            }
        }
    }
    cout << weight << endl;
}