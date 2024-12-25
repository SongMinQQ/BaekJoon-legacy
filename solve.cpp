#include <bits/stdc++.h>
using namespace std;

char a[102][102];
int n, result1 = 0, result2 = 0, y, x;
bool visited[102][102];
bool visited2[102][102];
const int dx[]= {-1, 0, 1, 0};
const int dy[]= {0, 1, 0, -1};

void bfs(int ay, int ax){
    queue<pair<int, int>> q;
    visited[ay][ax] = true;
    q.push({ay,ax});
    while(!q.empty()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i< 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(y < 0 || x < 0 || y >= n || x >=n || visited[ny][nx] == true) continue;
            if(a[y][x] == a[ny][nx]){
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
}

void bfs2(int ay, int ax){
    queue<pair<int, int>> q;
    visited2[ay][ax] = true;
    q.push({ay,ax});
    while(!q.empty()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i< 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(y < 0 || x < 0 || y >= n || x >=n || visited2[ny][nx] == true) continue;
            if((a[y][x] == 'R' || a[ny][nx] =='G') || 
            (a[y][x] == 'G' || a[ny][nx] =='R')){
                q.push({ny, nx});
                visited2[ny][nx] = true;
            }
        }
    }
}
int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            if(!visited[i][j]) {
                result1++;
                bfs(i,j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            if(!visited2[i][j]) {
                result2++;
                bfs2(i,j);
            }
        }
    }
    cout << result1 << ' ' << result2;
    return 0;
}