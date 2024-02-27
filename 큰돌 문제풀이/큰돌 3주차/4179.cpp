#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int r, c, y, x, fireVisited[1004][1004], jihoonVisited[1004][1004], result = 0, jihoonX, jihoonY;
char a[1004][1004];

bool in(int a,int b){
	return 0 <= a && a < r && 0 <= b && b < c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&fireVisited[0][0], &fireVisited[0][0] + 1004 * 1004, INF);
    // fill(&jihoonVisited[0][0], &jihoonVisited[1000][1001], 0);
    queue<pair<int,int>> q;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J'){
                jihoonY = i;
                jihoonX = j;
            } 
            else if(a[i][j] == 'F') {
                q.push({i, j});
                fireVisited[i][j] = 1;
            }
        }
    }

    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!in(ny,nx)) continue;
            if(fireVisited[ny][nx] != INF || a[ny][nx] == '#') continue;
            fireVisited[ny][nx] = fireVisited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    jihoonVisited[jihoonY][jihoonX] = 1;
    q.push({jihoonY, jihoonX});
    while(q.size()){
        int y = q.front().first;
		int x = q.front().second;
        q.pop();
        if(x == c - 1 || y == r - 1 || x == 0 || y == 0){
                result = jihoonVisited[y][x];
                break;
            }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!in(ny,nx)) continue;
            if(a[ny][nx] == '#' || jihoonVisited[ny][nx]) continue;
            if(fireVisited[ny][nx] <= jihoonVisited[y][x] + 1) continue;
            jihoonVisited[ny][nx] = jihoonVisited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(result != 0) cout << result << '\n';
    else cout << "IMPOSSIBLE\n";
    return 0;
}