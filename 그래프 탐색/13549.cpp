#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000002;
int n, k, visited[MAX];

int bfs(int n){
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        // +1, -1, *2 방향으로 BFS 탐색
        for(int i : {now * 2, now - 1, now + 1 }){
            if(0 <= i && i <= MAX && visited[i] == -1){
                visited[i] = visited[now] + 1;
                if(i == k) {return visited[k];}
                q.push(i);
            }
        }
    }
}
int main(){
    fill(visited, visited + 100001, -1);
    cin >> n >> k;
    visited[n] = 0;
    
    if(n == k) cout << 0;
    else cout << bfs(n) << '\n';
    return 0;
}