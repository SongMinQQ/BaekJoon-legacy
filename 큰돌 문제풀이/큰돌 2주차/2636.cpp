#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[101][101], y, x, m, n, findMax = 0, findNum;
bool visited[101][101];
queue<pair<int,int>> q;

void dfs(int y, int x){
    visited[y][x]= 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if((a[ny][nx] == 1) && (visited[ny][nx] == 0)){
            visited[ny][nx] = 1;
            q.push(make_pair(ny, nx));
            continue;
        }
        if((a[ny][nx] == 0) && (visited[ny][nx] == 0)){
            dfs(ny,nx);
        }
    }
}
void cheese(){
    findNum = q.size();
    while(!q.empty()){
        a[q.front().first][q.front().second] = 0;
        q.pop();
    }
    findMax++;
}

bool check(){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1) return true;
        }
    }
    
    return false;
}
int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    dfs(0, 0);
    while(check()){
        if(q.size() > 0) {
            cheese();
            fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
            dfs(0,0);
        }
    }
    cout << findMax << '\n' << findNum;
    return 0;
}