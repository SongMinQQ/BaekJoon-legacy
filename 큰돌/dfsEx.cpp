/*
연결된 육지는 모두 오염
바다로는 갈 수 없다.
오염시킬수 있는 방향은 상 하 좌 우 네방향
최소 몇번을 이동해야 모든 육지를 오염시킬 수 있는가?
1 : 육지 0 : 바다

범위 
1 <= N <= 100
1 <= M <= 100

예제 입력

입력은 맵의 세로길이 N과 가로길이 M이 주어진다. N * M의 맵이 주어진다.
5 5
1 0 1 0 1
1 1 0 0 1
0 0 0 1 1
0 0 0 1 1
0 1 0 0 0

출력
4
*/
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, findCount = 0;

void dfs(int y, int x, int **ajm){
    ajm[y][x] = 0;
    int check = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
            check++;
            if(check == 4){
                findCount++;
                return;
            }
            continue;
        }
        if(ajm[ny][nx] != 1) {
            check++;
            if(check == 4){
                findCount++;
                return;
            }
            continue;
        }
        if(ajm[ny][nx] == 1){
            dfs(ny,nx,ajm);
            return;
        }
    }
}
int main(){
    int num;
    cin >> n >> m;
    int **ajm = new int*[n];
    for(int i = 0; i < n; i++){
        ajm[i] = new int[m];
    }

    for(int i = 0; i < n; i++){
        for(int j= 0; j < m; j++){
            cin >> ajm[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j= 0; j < m; j++){
            if(ajm[i][j] == 1){
                dfs(i, j, ajm);
            }
        }
    }
    cout << findCount;
    return 0;
}