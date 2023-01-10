#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int> > g[MAXN];
int d[MAXN];
int n;
set<pair<int, int> > st;

void dijkstra(int s){
    for(int i = 1; i <= n; i++){
        i == s ? d[i] = 0 : d[i] = INF;
        st.insert(make_pair(d[i], i));
    }

    for(int i = 0 ; i < n; i++){
        pair<int, int> p = *(st.begin());
        st.erase(p);

        int u = p.second;
        int du = p.first;

        if(du == INF) break;

        for(int j = 0; j< g[u].size(); j++){
            p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > w && d[v] > d[u]){
                st.erase(make_pair(d[v], v));
                d[v] = max(d[u], w);
                st.insert(make_pair(d[v], v));
            }
        }
    }
}

int main(){
    cin >> n;
    pair<int, int> city[n];
    for(int i = 0; i < n; i++) cin >> city[i].first >> city[i].second;

    for(int i = 0 ; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w = abs(city[i].first - city[j].first) + abs(city[i].second-city[j].second);
            g[i+1].push_back(make_pair(j+1, w));
            g[j+1].push_back(make_pair(i+1, w));
        }
    }
    
    dijkstra(1);
    cout << d[n];
}