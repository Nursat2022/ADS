#include<bits/stdc++.h>

using namespace std;

int main(){
    queue<string> q1, q2, q3;

    int n;
    string s;
    while(cin >> n){
        if(n == 9){
            cin >> s;
            q1.push(s);
        }
        else if(n == 10){
            cin >> s;
            q2.push(s);
        }
        else if(n == 11){
            cin >> s;
            q3.push(s);
        }
    }
    
    while(!q1.empty()){
        cout << "9 " << q1.front() << endl;
        q1.pop();
    }
    while(!q2.empty()){
        cout << "10 " << q2.front() << endl;
        q2.pop();
    }
    while(!q3.empty()){
        cout << "11 " << q3.front() << endl;
        q3.pop();
    }


}
