#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define ull unsigned long long

vector<pair<ull, pair<ull, ull> > > g;
vector<ull> p;

ull dsu(ull v){
    return v == p[v] ? v : p[v] = dsu(p[v]);
}

bool dsu2(ull a, ull b){
    a = dsu(a);
    b = dsu(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main() {
	ull n, m;
	cin >> n >> m;
	for(ull i = 0; i < m; i++) {
		ull a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g.push_back(make_pair(c, make_pair(a, b)));
	}

	ull ans = 0;

	sort(g.begin(), g.end());

	for (ull i = 0; i < n; ++i) p.push_back(i);
	
	for (ull i = 0; i < g.size(); ++i){
		ull u = g[i].second.first, v = g[i].second.second;
		ull t = g[i].first;
		for(ull j = u + 1; j <= v; j++){
			if (dsu(u) != dsu(j)) {
				ans += t;
				dsu2(u, j);
			}
			else j = p[u];
		}
	}
	cout << ans;
}