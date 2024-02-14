#include <bits/stdc++.h>
using namespace std;

int n, m, num1, num2, result = 0;
vector<int> v[104];
bool visited[104];

void dfs(int a){
    visited[a] = 1;
    for(int i: v[a]){
        if(visited[i] == 0) dfs(i);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    dfs(1);
    for(int i = 2; i < 104; i++){
        if(visited[i] == 1) result += 1;
    }
    cout << result;
    return 0;
}