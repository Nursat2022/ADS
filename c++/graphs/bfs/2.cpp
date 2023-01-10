#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int y[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int d[25][25];
pair<int, int> p[25][25];

int main(){
    int n; cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++) d[i][j] = 1e9;
    }
    d[x1][y1] = 0;
    p[x1][y1] = make_pair(-1, -1);
    queue<pair<int, int> > q;
    q.push(make_pair(x1, y1));

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k = 0; k < 8; k++){
            int toX = i + x[k];
            int toY = j + y[k];
            if(toX > 0 && toY > 0 && toX <= n && toY <= n){
                if(d[toX][toY] > d[i][j] + 1){
                    d[toX][toY] = d[i][j] + 1;
                    q.push(make_pair(toX, toY));
                    p[toX][toY] = make_pair(i, j);
                }
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++) cout << d[i][j] << " ";
    //     cout << endl;
    // }
    cout << endl;
    cout << d[x2][y2] << "\n";
    vector<pair<int, int> > path;

    for(pair<int, int> v = make_pair(x2, y2); v.first != -1; v = p[v.first][v.second]){
        // cout << v.first << " " << v.second << "\n";
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++){
        cout << path[i].first << " " << path[i].second << "\n";
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++) cout << p[i][j].first << "," << p[i][j].second << "\t\t";
    //     cout << endl;
    // }
}