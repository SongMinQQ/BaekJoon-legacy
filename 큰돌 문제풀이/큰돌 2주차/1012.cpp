#include <bits/stdc++.h>
using namespace std;

int T, m, n, k, findCount;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int **ajm, bool **visited){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
        }
        if(ajm[ny][nx] == 1 && !visited[ny][nx]){
            dfs(ny, nx, ajm, visited);
        }
    }
}
int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        findCount = 0;
        cin >> m >> n >> k;
        int **ajm = new int*[n];
        bool **visited = new bool*[n];
        for(int i = 0; i < n; i++){
            ajm[i] = new int[m];
            visited[i] = new bool[m];
            fill(ajm[i], ajm[i]+m, 0);
        }
        
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            ajm[y][x] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ajm[i][j] == 1 && !visited[i][j]){
                    findCount++; dfs(i, j, ajm, visited);
                }
            }
        }
        cout << findCount << '\n';
        
    }
    return 0;
}