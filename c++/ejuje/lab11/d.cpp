#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int> > graph[100000];
bool used[100000];

int main(){
    int n; cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int num; cin >> num;
            if(i != j) graph[i].push_back(make_pair(j, num));
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