#include <bits/stdc++.h>
using namespace std;

int n, m, visited[10001], a, b, NodeDistance[10001], findMax=0;
vector<int> v[10001];

int dfs(int here){
    visited[here] = 1;
    int ret = 1;
    for(int i : v[here]){
        if(visited[i]) continue;
        ret += dfs(i);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        fill(visited,visited + 10001,0);
        NodeDistance[i] = dfs(i);
        findMax = max(NodeDistance[i], findMax);
    }
    for(int i = 0; i <=n; i++){
        if(findMax == NodeDistance[i]){
            cout << i << ' ';
        }
    }
    return 0;
}