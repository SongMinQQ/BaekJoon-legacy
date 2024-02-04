#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[1004][1004], visited[1004][1004];
queue<pair<int,int>> q;

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] != -1 || a[ny][nx] == 0) continue;
            if (a[ny][nx] == 1) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main(){
    fill(&visited[0][0], &visited[0][0] + 1004 * 1004, -1);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) {
                q.push(make_pair(i,j));
                visited[i][j] = 0;
            }
            if(a[i][j] == 0){
                visited[i][j] = 0;
            }
        }
    }
    bfs();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}