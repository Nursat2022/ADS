#include<bits/stdc++.h>

using namespace std;

int main(){
    deque<int> d;
    char z;
    while(cin >> z){
        int x;
        if(z == '+'){
            cin >> x;
            d.push_front(x);
        }
        else if(z == '-'){
            cin >> x;
            d.push_back(x);
        }
        else if(z == '*'){
            if(d.empty()){
                cout << "error" << endl;
            }
            else{
                cout << d.front() + d.back() << endl;
                if(d.size() == 1) d.pop_back();
                else{
                    d.pop_back();
                    d.pop_front();
                }
            }
        }
        else break;
    }

}