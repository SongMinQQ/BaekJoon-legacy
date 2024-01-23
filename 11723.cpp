#include <bits/stdc++.h>
using namespace std;

int x, m;
string order;
set<int> S;
set<int> allSet = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> order;
        if(order == "add"){
            cin >> x;
            S.insert(x);
        }
        else if(order == "remove"){
            cin >> x;
            S.erase(x);
        }
        else if(order == "check"){
            cin >> x;
            if(S.find(x) != S.end()){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if(order == "toggle"){
            cin >> x;
            if(S.find(x) != S.end()){
                S.erase(x);
            }
            else{
                S.insert(x);
            }
        }
        else if(order == "all"){
            S = allSet;
        }
        else if(order == "empty"){
            S.clear();
        }
    }
    return 0;
}