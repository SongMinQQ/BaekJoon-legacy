#include <bits/stdc++.h>
using namespace std;

int  n, visited[62][62][62], num[3]={};

int attack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};
struct scv{
    int a, b, c;
};
queue<scv> q;

void bfs(int a, int b, int c){
    visited[a][b][c] = 1;
    q.push({a,b,c});
    while(q.size()){
        int currentA = q.front().a;
        int currentB = q.front().b;
        int currentC = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++){
            //음수 방지
            int na = max(0, currentA - attack[i][0]);
            int nb = max(0, currentB - attack[i][1]);
            int nc = max(0, currentC - attack[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[currentA][currentB][currentC] + 1;
            q.push({na, nb, nc});
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    bfs(num[0], num[1], num[2]);
    cout << visited[0][0][0] -1;
    return 0;
}