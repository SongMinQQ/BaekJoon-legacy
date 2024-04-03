#include <bits/stdc++.h>
using namespace std;

int visited[102], n, m, x, y, cur;
vector<int> v[102];
queue<int> q;

void bfs(){
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i = 1; i <= 6; i++){
            int next = cur + i;
            if(cur == 99){
                visited[cur] = min(visited[cur],visited[s] + 1);
            }
            if(next >= 100) continue;
            if(!visited[next]){ // 방문하지 않은 경우에만 처리
                visited[next] = visited[cur] + 1;
                if(!v[next].empty()){ // 연결된 노드가 있는 경우
                    for(int u : v[next]){
                        if(!visited[u]){
                            q.push(u);
                        }
                    }
                } else { // 연결된 노드가 없는 경우
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        cin >> x >> y;
        v[x].push_back(y);
    }
    q.push(0);
    visited[99] = 999999;
    bfs(0);
    cout << visited[99] - 1;
    return 0;
}