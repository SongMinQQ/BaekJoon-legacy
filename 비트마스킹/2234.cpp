#include <bits/stdc++.h>
using namespace std;

int m, n, castle[52][52], rooms = 0, biggest = 0, roomSize[2555];
int visited[52][52];
int dx[4] = {-1, 0, 1, 0};  // 서, 북, 동, 남에 해당
int dy[4] = {0, -1, 0, 1};

int dfs(int y, int x, int cnt) {
    if(visited[y][x]) return 0;
    visited[y][x] = cnt;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!(castle[y][x] & (1 << i))) {  // 벽이 없을 경우에만 이동
            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
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
                rooms++;
                roomSize[rooms] = dfs(i, j, rooms);
                biggest = max(biggest, roomSize[rooms]);
            }
        }
    }

    cout << rooms << '\n' << biggest << '\n';
    return 0;
}
