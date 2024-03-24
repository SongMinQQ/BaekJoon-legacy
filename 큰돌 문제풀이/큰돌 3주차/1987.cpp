#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, result = 0;
char a[22][22];
bool visited[28];

void dfs(int y, int x, int count) {
    result = max(result, count);
    visited[a[y][x] - 'A'] = true;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && nx >= 0 && ny < r && nx < c && !visited[a[ny][nx] - 'A']) {
            dfs(ny, nx, count + 1);
        }
    }

    visited[a[y][x] - 'A'] = false;
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); j++) {
            a[i][j] = line[j];
        }
    }

    dfs(0, 0, 1);
    cout << result;
    return 0;
}
