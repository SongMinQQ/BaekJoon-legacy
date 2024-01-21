#include <bits/stdc++.h>
using namespace std;

int n, m, v;

void dfs(int v, int *visited, vector<int> *adj){
    visited[v] = 1;
    cout << v << ' ';
    sort(adj[v].begin(),adj[v].end());
    for(int a : adj[v]){
        if(visited[a] == 0){
            dfs(a, visited, adj);
        }
    }
    return;
}

queue<int> q;
stack<int> s;

void bfs(int v, int *visited, vector<int> *adj){
    visited[v] = 1;
    q.push(v);
    while(!q.empty()){
            int current = q.front();
            q.pop();
            cout << current << ' ';
        for(int a : adj[current]){
            if(visited[a] == 0){
                visited[a] = 1;
                q.push(a);
            }
        }
    }
    return;
}
int main(){
    int node, nextNode;
    cin >> n >> m >> v;
    int *visited = new int[n + 1];
    int *visited2 = new int[n + 1];
    memset(visited, 0, (n+1) * sizeof(int));
    memset(visited2, 0, (n+1) * sizeof(int));
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        cin >> node >> nextNode;
        adj[node].push_back(nextNode);
        adj[nextNode].push_back(node);
    }
    dfs(v, visited, adj);
    cout << '\n';
    bfs(v, visited2, adj);
}