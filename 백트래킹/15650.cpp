#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<bool> visited;

void makeVector(int a){
    visited.assign(n + 1, false);
    if(v.size() == m) {
        for(int i : v){
                cout << i << ' ';
            }
            cout << '\n';
        return;
    }
    for(int i = a; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            v.push_back(i);
            makeVector(i + 1);
            v.pop_back();
        }
    }
}
int main(){
    cin >> n >> m;
    visited.assign(n + 1, false);
    makeVector(1);
    return 0;
}