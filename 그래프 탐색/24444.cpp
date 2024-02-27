#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int n, m, r, num1, num2;
int visited[100001], order = 0;

bool compare(int a, int b){
    return b < a;
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = ++order; 
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : v[node]) {
            if (visited[i] == 0) {
                q.push(i);
                visited[i] = ++order; 
            }
        }
    }
}

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1); 
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }
    bfs(r);
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}
