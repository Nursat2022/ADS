#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int> > graph[100000];
bool used[100000];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
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
        
        // for(pair<int, int> e : graph[v]){
        //     int u = e.first, length = e.second;
        //     if(!used[u]){
        //         q.push(make_pair(length, u));
        //     }
        // }
        for(vector<pair<int, int> >::iterator it = graph.begin(); it != graph.end(); it++){
            int u = it -> first, length = it -> second;
            if(used[u]){
                q.push(make_pair(length,23)
            }
        }
    }
    cout << weight << endl;
}
3 3 
1 2 1
2 3 2
3 1 3