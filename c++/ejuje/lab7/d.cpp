#include<bits/stdc++.h>

using namespace std;

struct Student{
    string surname;
    string name;
    double overall;
};

bool cmp(Student s1, Student s2){
    if(s1.overall == s2.overall){
        if(s1.surname == s2.surname){
            return s1.name < s2.name;
        }
        return s1.surname < s2.surname;
    }
    return s1.overall < s2.overall;
}

void merge(vector<Student> &st, int l, int mid, int r){
    int i = l, j = mid + 1, k = l;
    Student a[r + 1];
    while(i <= mid && j <= r){
        if(cmp(st[i], st[j])) a[k++] = st[i++];
        else a[k++] = st[j++];
    }
    while(i <= mid) a[k++] = st[i++];
    while(j <= r) a[k++] = st[j++];
    for(int i = l; i <= r; i++) st[i] = a[i];
}

void mergeSort(vector<Student> &st, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        mergeSort(st, l, mid);
        mergeSort(st, mid + 1, r);
        merge(st, l, mid, r);
    }
}

int main(){
    int n; cin >> n;
    vector<Student> st(n);
    map<string, double> mp;
    mp["A+"] = 4.0;
    mp["A"] = 3.75;
    mp["B+"] = 3.5;
    mp["B"] = 3.0;
    mp["C+"] = 2.5;
    mp["C"] = 2.0;
    mp["D+"] = 1.5;
    mp["D"] = 1.0;
    mp["F"] = 0;

    for(auto &student : st){
        cin >> student.surname >> student.name;
        int m; cin >> m;
        double sum = 0, sum2 = 0;
        while(m--){
            string mark; int credits;
            cin >> mark >> credits;
            sum += mp[mark] * credits;
            sum2 += credits;
        }
        student.overall = sum/sum2;
    }
    mergeSort(st, 0, st.size()-1);
    for(auto &i : st){
        cout << i.surname << " " << i.name << " " << fixed << setprecision(3) << i.overall << endl;
    }
}