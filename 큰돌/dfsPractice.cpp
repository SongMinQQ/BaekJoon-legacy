#include <bits/stdc++.h>
using namespace std;

const int n = 5;
vector<int> adj[n];
int visited[n];

void dfs(int u){
    visited[u] = 1;
    for(int num : adj[u]){
        if(visited[num] != 1) dfs(num);
    }
}