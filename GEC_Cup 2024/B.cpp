#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};
int n, m, cur = -1;
char a[102][102];
bool escape;
bool visited[102][102];
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(a[ny][nx] == 'X' && visited[ny][nx] == 0){
            dfs(ny, nx);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            a[i][j] = line[j];
        }
    }
    // for(int i = 0; i < n - 1; i++){
    //     for(int j = 0; j < m; j++){
    //         if(a[i][j] == 'X' && j + 1 >= cur) {
    //             cur = j + 1;
    //             break;
    //         }
    //     }
    // }
    // for(int i = 0; i < m; i++){
    //     if(a[n - 1][i] == 'X' && i + 1 >= cur){
    //         escape = true;
    //         cur = i + 1;
    //         break;
    //     }
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'X' &&visited[i][j] == 0){
                dfs(i, j);
                break;
            }
        }
        break;
    }
    for(int i = 0; i < m; i++){
        if(visited[n-1][i] == 1) {
            cur = i;
            escape = true;
            break;
        }
    }
    // for(int i = 0; i < m; i++){
    //     int cnt = 0;
    //     for(int j = 0; j < n; j++){
    //         if(visited[j][i] == 1){
    //             cur = i + 1;
    //             cnt++;
    //         }
    //     }
    //     if(cnt == n) {
    //         escape = true;
    //         break;
    //     }
    // }
    if(escape) cout << cur + 1;
    else cout << "ESCAPE FAILED";
    return 0;
}