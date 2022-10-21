#include<bits/stdc++.h>

using namespace std;

struct human{
    int age;
    string name;
};

bool cmp(human a, human b){
    return a.age < b.age;
}

int main(){
    int n; cin >> n;
    human a[n];
    for(int i = 0; i < n; i++) cin >> a[i].age >> a[i].name;
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++) cout << a[i].age << " " << a[i].name << endl;
}