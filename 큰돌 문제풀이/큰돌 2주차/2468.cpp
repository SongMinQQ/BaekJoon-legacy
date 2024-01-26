#include <bits/stdc++.h>
using namespace std;

int n, maxNum = 0;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool visited[101][101];

void dfs(int y, int x, int **ajm, int d){
    visited[y][x]= 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(ajm[ny][nx] > d && !visited[ny][nx]){
            dfs(ny,nx,ajm, d);
        }
    }

}
int main(){
    cin >> n;
    int **ajm = new int*[n];

    for(int i = 0; i < n; i++){
        ajm[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ajm[i][j];
        }
    }
    for(int d = 0; d < 101; d++){
        int cnt = 0;
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ajm[i][j] > d && !visited[i][j]){
                    dfs(i, j, ajm, d);
                    cnt++;
                }
            }
        }
        maxNum = max(maxNum, cnt);
    }
    cout << maxNum;
}