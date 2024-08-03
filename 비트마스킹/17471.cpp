#include <bits/stdc++.h>
using namespace std;

vector<int> v[11];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, nodeNum[11], a, b, visited[11], comp[11], ret = 987654321;

pair<int, int> dfs(int here, int value){
    visited[here] = 1;
    pair<int, int> ret = {1, nodeNum[here]};
    for(int there: v[here]){
        if(comp[there] != value) continue;
        if(visited[there]) continue;
        pair<int, int> _temp = dfs(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> nodeNum[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            v[i].push_back(b);
            v[b].push_back(i);
        }
    }
    for(int i = 1; i < (1 << n) - 1; i++){
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                comp[j + 1] = 1; idx1 = j + 1;
            }
            else idx2 = j + 1;
        }
        pair<int,int> v1 = dfs(idx1, 1);
        pair<int,int> v2 = dfs(idx2, 0);
        if(v1.first + v2.first == n) ret = min(ret, abs(v1.second - v2.second));
    }
    cout << (ret == 987654321 ? -1 : ret) << '\n';
}