#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    if (n == 1 || n == 2){
        cout << n-1;
        return 0;
    }
    set<int> st;
    for(int i = 2; i*i <= n; i++){
        while(n % i == 0){
            st.insert(i);
            n /= i;
        }
    }
    (n > 2) ? cout << st.size() + 1 : cout << st.size();
}