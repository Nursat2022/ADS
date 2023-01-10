#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1005;
int a[N][N];
queue<pair<int, int> > marios;
int n, m, answer = 0;

void changes(int i, int j){
    // cout << i << " " << j << endl;
    if(i + 1 <= n && i + 1 >= 1 && a[i + 1][j] == 1){
        a[i + 1][j] = 2;
        marios.push(make_pair(i + 1, j));
    }
    if(i - 1 >= 1 && i - 1 <= n && a[i - 1][j] == 1){
        a[i - 1][j] = 2;
        marios.push(make_pair(i - 1, j));
    }
    if(j + 1 >= 1 && j + 1 <= m && a[i][j + 1] == 1){
        a[i][j + 1] = 2;
        marios.push(make_pair(i, j + 1));
    }
    if(j - 1 >= 1 && j - 1 <= m && a[i][j - 1] == 1){
        a[i][j - 1] = 2;
        marios.push(make_pair(i, j - 1));
    }
}

int main(){
    cin >> n >> m;
    int numOfOnes = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) marios.push(make_pair(i, j));
            else if(a[i][j] == 1) numOfOnes++;
        }
    }

    int numOfMarios = marios.size();
    int cntMarios = 0;
    while(!marios.empty()){
        pair<int, int> p = marios.front();
        if(numOfMarios == 0){
            answer++;
            cntMarios += marios.size();
            numOfMarios = marios.size();
        }
        marios.pop();
        numOfMarios--;
        int i = p.first, j = p.second;
        changes(i, j);
    }

    cntMarios == numOfOnes ? cout << answer : cout << -1;

}