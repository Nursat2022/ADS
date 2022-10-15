#include <bits/stdc++.h> 
 
using namespace std; 
 
int getLastCompetitor(vector<int> &competitors, int power) { 
    if(power < competitors[0]) 
        return -1; 
    int l = 0, r = competitors.size(); 
    while(l + 1 < r) { 
        int mid = (l+r)/2; 
        if(competitors[mid] <= power) 
            l = mid; 
        else 
            r = mid; 
    } 
    return l; 
} 
 
int main() { 
    int n; cin >> n;
    vector<int> competitors(n); 
    vector<int> prefSum(n); 
    for(int &i : competitors) cin >> i;
    sort(competitors.begin(), competitors.end()); 
    prefSum[0] = competitors[0]; 
    for(int i = 1; i < n; i++) prefSum[i] = competitors[i] + prefSum[i-1]; 
    int tests; cin >> tests;
    while (tests--) { 
        int power; cin >> power; 
        int id = getLastCompetitor(competitors, power); 
        cout << (id != -1? id+1: 0) << ' ' << (id != -1 ? prefSum[id]: 0) << endl; 
    } 
 
    return 0; 
}