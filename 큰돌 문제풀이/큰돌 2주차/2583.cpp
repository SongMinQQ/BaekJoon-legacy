#include <bits/stdc++.h>
using namespace std;

// int visited[101][101];
int m, n, k, y, x, y2, x2, area, visited[104][104], a[104][104];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<int> ret;
int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx] == 1) continue;
        if(a[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> x >> y >> x2 >> y2;
        for(int j = x; j < x2; j++){
            for(int k = y; k < y2; k++){
                a[k][j] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != 1 & visited[i][j] == 0){
                ret.push_back(dfs(i,j));
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for(int a : ret) cout << a << ' ';
    return 0;
}