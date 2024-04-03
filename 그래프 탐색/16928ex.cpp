#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 102;
int visited[MAX_N], n, m, x, y;
vector<int> v[MAX_N];

void bfs(int start) {
    for(int i = 0; i < MAX_N; i++) visited[i] = 999999;
    queue<int> q;
    q.push(start);
    visited[start] = 0; 

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 1; i <= 6; i++) { 
            int next = cur + i;
            if (next > 100) continue; 
            if (!v[next].empty()) { 
                for (int u : v[next]) {
                    if (visited[u] > visited[cur] + 1) {
                        visited[u] = visited[cur] + 1;
                        q.push(u);
                    }
                }
            } else { 
                if (visited[next] > visited[cur] + 1) {
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        cin >> x >> y;
        v[x].push_back(y); 
    }

    bfs(1);
    cout << visited[100];
    return 0;
}
