#include<iostream>
#include<vector>
#include<queue>
#include<set> 

using namespace std; 

vector<int>g_r[410]; 
vector<int>g_a[410]; 
int arr[405][405]; 

int main(){ 
    int n, m; 
    cin >> n >> m;

    for(int i = 0; i < m; i++){ 
        int a, b; 
        cin >> a >> b; 
        a--; b--; 
        g_r[a].push_back(b); 
        g_r[b].push_back(a); 
        arr[a][b] = 1; 
        arr[b][a] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (arr[i][j] == 0 && i != j) g_a[i].push_back(j); 
        } 
    } 
    queue<int> q1; 
    vector<int> d1(n+1); 
    vector<bool> used1(n+1); 
    q1.push(0); 
    used1[0] = true; 
    while(!q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i = 0; i < g_r[v].size(); i++){ 
            int to = g_r[v][i]; 
            if(!used1[to]){ 
                used1[to] = true; 
                q1.push(to); 
                d1[to] = d1[v] + 1; 
            } 
        } 
    } 
    queue<int> q2; 
    vector<int> d2(n+1); 
    vector<bool> used2(n+1); 
    q2.push(0); 
    used2[0] = true; 
    while(!q2.empty()){ 
        int v = q2.front(); 
        q2.pop(); 
        for(int i = 0; i < g_a[v].size(); i++){ 
            int to = g_a[v][i]; 
            if(!used2[to]){ 
                used2[to] = true; 
                q2.push(to); 
                d2[to] = d2[v] + 1; 
            } 
        } 
    } 
     
    !used1[n-1] || !used2[n-1] ? cout << -1 : cout << max(d1[n-1], d2[n-1]);
}