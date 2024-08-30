#include <bits/stdc++.h>
using namespace std;

int m, n, castle[52][52], cnt = 0, biggest = 0;
int visited[52][52];
int dx[4] = {-1, 0, 1, 0};  // 서, 북, 동, 남에 해당
int dy[4] = {0, -1, 0, 1};

int dfs(int y, int x, int cnt) {
    for (int i = 0; i < 4; i++) {
        if(visited[y][x]) return 0;
        visited[y][x] = cnt;
        int ret = 1;
        if (!castle[y][x] & (1 << i)) {  // 벽이 없을 경우에만 이동
            int ny = y + dy[i];
            int nx = x + dx[i];
            visited[ny][nx] = visited[y][x] + 1;
            dfs(ny, nx, cnt);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> castle[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                cnt++;
                visited[i][j] = 1;
                dfs(i, j, cnt);
            }
        }
    }

    cout << cnt << '\n' << biggest << '\n';
    return 0;
}
