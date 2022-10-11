// #include<bits/stdc++.h>

// using namespace std;

// void res(int index, string s, vector<bool> &v){
//     int i;
//     if(index == s.size()-1) i = 0;
//     else i = index + 1;
//     while(i < s.size()){
//         if(s[i] != s[index] && v[i] == true && v[index] == true){
//             v[i] = false;
//             return;
//         }
//         i++;
//     }
// }

// int main(){
//     int n; cin >> n;
//     string s; cin >> s;
//     map<char, string> ans;
//     ans['S'] = "SAKAYANAGI";
//     ans['K'] = "KATSURAGI";
//     vector<bool> v(n, true);
//     for(int i = 0; i < s.size(); i++){
//         res(i, s, v);
//     }
//     for(int i = 0; i < v.size(); i++){
//         if(v[i] == true) cout << ans[s[i]];
//         return 0;
//     }
// }


#include<bits/stdc++.h>

using namespace std;

void change(int index, vector<bool> &v, string s){
    int i;
    if(index == s.size()-1) i = 0;
    else i = index + 1;
    
    while(i < s.size()){
        if(s[i] != s[index] && v[i] == true){
            v[i] = false;
            return;
        }
        i++;
    }
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    map<char, stack<char>> mp;
    vector<bool> v(n, true);

    for(int i = 0; i < s.size(); i++){
        mp[s[i]].push(s[i]);
    }

    int i = 0;
    while(!mp['S'].empty() && !mp['K'].empty() && i < s.size()){
        if(s[i] == 'K' && v[i] == true){
            mp['S'].pop();
            change(i, v, s);
        }        
        else if(s[i] == 'S' && v[i] == true){
            mp['K'].pop();
            change(i, v, s);
        }        
        i++;
        if(i == s.size()) i = 0;
    }

    if(mp['K'].empty()) cout << "SAKAYANAGI";
    else cout << "KATSURAGI";

    // for(auto i : mp){
    //     while(!i.second.empty()){
    //         cout << i.second.top() << " ";
    //         i.second.pop();
    //     }
    //     cout << endl;
    // }
}