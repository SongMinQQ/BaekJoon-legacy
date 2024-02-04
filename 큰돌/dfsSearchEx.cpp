#include <bits/stdc++.h>
using namespace std;

int n, m, visited[1004];
vector<int> v[1004];

int dfs(int here){
    int ret = 1;
    for(int i : v[here]){
        if(visited[i]) continue;
        visited[i] = 1;
        ret += dfs(i);
    }
    return ret;
}
int main(){
    cin >> n >> m;
    v[1].push_back(2);
    v[1].push_back(3);
    visited[1] = 1;
    cout << dfs(1) <<'\n';
    return 0;
}