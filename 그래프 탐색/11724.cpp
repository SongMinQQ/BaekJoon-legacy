#include <bits/stdc++.h>
using namespace std;

bool visited[1009];
vector<int> v[1009];
int n, m, num1, num2, result = 0;

void dfs(int a){
    visited[a] = 1;
    for(int node : v[a]){
        if(visited[node] == 0){
            dfs(node);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    for(int i = 1; i <= n; i++){
        if(!v[i].empty() && visited[i] == 0){
            dfs(i);
            result++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(v[i].empty() && visited[i] == 0){
            visited[i] = 1;
            result++;
        }
    }
    cout << result;
}