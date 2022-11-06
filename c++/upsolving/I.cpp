#include<bits/stdc++.h>

using namespace std;

bool check(long long n){
    stack<int> st;
    while(n){
        int num = n % 2;
        if(st.empty()) st.push(num);
        else if(st.top() == 0 && num == 1)
            st.pop();
        else st.push(num);    
        n /= 2;
    }
    return (st.empty()) ? true : false;
}

int main(){
    int n; cin >> n;
    while(n--){
        long long x; cin >> x;
        check(x) ? cout << "YES\n" : cout << "NO\n";
    }
}