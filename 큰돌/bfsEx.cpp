/*
당근마켓 엔지니어 승원이
당근차는 한칸 움직일 때마다 당근 한개가 소모된다.
최단거리로 당근마켓에 향할 때 당근 몇개를 소모해야 당근마켓에 갈 수 있는가?
승원이는 상하좌우로만 갈수 있고 맵의 1은 육지, 0은 바다이다.
오로지 육지로만 이동 가능하다.

입력
맵의 세로길이 N 가로길이 M N*M의 맵이 주어진다.

출력
당근을 몇개 소모해야 하는지 출력하라

예제입력
5 5
0 0
4 4
1 0 1 0 1
1 1 1 0 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1

예제출력
9
*/
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, startx, starty, endx, endy, findCount=0, y, x;

void bfs(int **ajm, int **visited){
    queue<pair<int, int>> q;
    visited[starty][startx] = 1;
    q.push({starty, startx});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visited[ny][nx]) continue;
            // if(ajm[ny][nx] >= 1){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            // }
        }
    }
}

int main(){
    cin >> n >> m;
    int **ajm = new int*[n];
    int **visited = new int*[n];
    for(int i = 0; i < n; i++){
        ajm[i] = new int[m];
        visited[i] = new int[m];
    }
    cin >> starty >> startx >> endy >> endx;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ajm[i][j];
            visited[i][j] = 0;
        }
    }
    bfs(ajm, visited);
    cout << visited[endy][endx];
    return 0;
}
