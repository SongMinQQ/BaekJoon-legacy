#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char a[302][302];
int x1, y12, x2, y2, n, m, cnt = 0, visited[302][302];
bool isCatched;

void dfs(int s, int e){
    visited[s][e] = 1;
    for(int i = 0; i < 4; i++){
        int ny = s + dy[i];
        int nx = e + dx[i];
        if(ny < 0 || nx < 0 || ny > n || nx > m || visited[ny][nx] == 1) continue;
        if(a[ny][nx] == '#'){
            visited[ny][nx] = 1;
            isCatched = true;
            return;
        }
        if(a[ny][nx] == '0') {
            // visited[ny][nx] = 1;
            dfs(ny,nx);
        }
        if(a[ny][nx] == '1') {
            visited[ny][nx] = 1;
            a[ny][nx] = '0';
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> x1 >> y12 >> x2 >> y2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    while(1){
        if(isCatched == true) break;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if(a[i][j] == '1' || a[i][j] == '#' || a[i][j] == '*')
                cnt++;
                dfs(x1 - 1, y12 - 1);
                fill(&visited[0][0], &visited[n-1][m], 0);
        //         break;
        //     }
        //     break;
        // }
    }

    cout << cnt;
    return 0;
}