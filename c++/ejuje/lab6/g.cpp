#include<bits/stdc++.h>

using namespace std;

struct Steam{
    string oldPass;
    string newPass;
};

bool cmp(Steam a, Steam b){
    return a.oldPass < b.oldPass;
}

int partition(vector<Steam> &steams, int low, int high){
    Steam pivot = steams[high];
    int i = low - 1;  
    for(int j = low; j < high; j++){
        if(cmp(steams[j], pivot)){
            i++;
            swap(steams[j], steams[i]);
        }
    }
    swap(steams[i + 1], steams[high]);
    return i + 1;
}

void quickSort(vector<Steam> &steams, int low, int high){
    if(low < high){
        int pi = partition(steams, low, high);
        quickSort(steams, low, pi - 1);
        quickSort(steams, pi + 1, high);
    }
}

pair<int, pair<bool, string>> Pass(vector<Steam> &steams, int l, int r, string x, int ind){
    while(l <= r){
        int mid = (l + r)/2;
        if(steams[mid].oldPass == x && mid != ind){
            string s = steams[mid].newPass;
            // cout << steams[mid].oldPass << " x = " << x << " s = " << s << " ";
            // steams.erase(steams.begin()+mid);
            return {mid, {true, s}};
        }
        else if(x > steams[mid].oldPass) l = mid + 1;
        else r = mid - 1;
    }
    return {0, {false, "false"}};
}

int main(){
    int n; cin >> n;
    vector<Steam> steams(n);
    for(auto &s : steams){
        cin >> s.oldPass >> s.newPass;
    }
    quickSort(steams, 0, steams.size()-1);
    // cout << endl;
    // for(auto i : steams){
    //     cout << i.oldPass << " " << i.newPass << endl;
    // }
    // cout << endl;
    for(int j = 0; j < steams.size(); j++){
        Steam &s = steams[j];
        pair<int, pair<bool, string>> p = Pass(steams, 0, steams.size()-1, s.newPass, j);
            // cout << "cur = " << s.oldPass << " " << s.newPass << endl;
            // for(auto i : steams){
            //     cout << i.oldPass << " " << i.newPass << endl;
            // }
            // cout << endl;
        if(p.second.first){
            // cout << s.oldPass << " true " << s.newPass << endl;
            s.newPass = p.second.second;
            steams.erase(steams.begin() + p.first);    
            j--;        
            // cout << s.oldPass << " true " << s.newPass << endl;
            // cout << endl;
            // p = Pass(steams, 0, steams.size()-1, s.newPass);
        }
    }
    cout << steams.size() << "\n";
    for(auto i : steams){
        cout << i.oldPass << " " << i.newPass << endl;
    }
}