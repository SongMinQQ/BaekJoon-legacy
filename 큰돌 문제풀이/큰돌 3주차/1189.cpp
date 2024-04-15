#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char a[6][6];
int visited[6][6];
int r, c, k, cnt = 0, y, x;

void dfs(int y, int x){
    if(y == 0 && x == c - 1){
        if(k == visited[y][x]) cnt++;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || a[ny][nx] == 'T' || visited[ny][nx]) continue;
        visited[ny][nx] = visited[y][x] + 1;
        dfs(ny, nx);
        visited[ny][nx] = 0;
    }
    }

int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            a[i][j] = line[j];
        }
    }
    visited[r-1][0] = 1;
    dfs(r - 1, 0);
    cout << cnt;
    return 0;
}