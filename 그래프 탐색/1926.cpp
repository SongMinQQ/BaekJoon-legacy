#include<bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[503][503], visited[503][503], cnt = 0, maxNum = 0, cy, cx;
queue<pair<int, int>> q;
void bfs(int y, int x) {
    int localMax = 1;
    while (!q.empty()) {
        tie(cy, cx) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0 || visited[ny][nx] != 0) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
            localMax++;
        }
    }
    maxNum = max(maxNum, localMax);
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0 && a[i][j] == 1){
                cnt++;
                q.push({i, j});
                visited[i][j] = 1;
                bfs(i, j);
            }
        }
    }
    cout << cnt << '\n' << maxNum;
    return 0;
}