#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e9;
vector<vector<int> > d(505, vector<int> (505, MAXN));
vector<vector<int> > v(505, vector<int> (505, MAXN));
int res = 0;
vector<int> arr;
int n;

void func(int k) {
  res = 0;
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < arr.size(); ++j) {
      v[arr[j]][k] = min(v[arr[j]][k], v[arr[j]][arr[i]] + v[arr[i]][k]);
    }
  }




  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < arr.size(); ++j) {
      v[k][arr[j]] = min(v[k][arr[j]], v[k][arr[i]] + v[arr[i]][arr[j]]);
    }
  }

  

  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < arr.size(); ++j) {
      v[arr[i]][arr[j]] = min(v[arr[i]][arr[j]], v[arr[i]][k] + v[k][arr[j]]);
      if (v[arr[i]][arr[j]] < MAXN and v[arr[i]][arr[j]] > res) 
        res = v[arr[i]][arr[j]];
    }
  }

}

int main() {

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> d[i][j];
      if (d[i][j] == 0 && i != j) d[i][j] = MAXN;
      if (i == j) v[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    arr.push_back(x);
    for (int j = 0; j < arr.size(); ++j) {
      v[x][arr[j]] = d[x][arr[j]];
      v[arr[j]][x] = d[arr[j]][x];
    } 
    func(x);
    cout << res << "\n";
  }

  

}