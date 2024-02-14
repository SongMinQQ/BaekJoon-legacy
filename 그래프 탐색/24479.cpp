#include <bits/stdc++.h>
using namespace std;

int n, m, r, num1, num2, setCount = 0;
vector<int> v[100004];
int visited[100004];

bool compare(int a, int b){
    return b < a;
}
void dfs(int a){
    sort(v[a].begin(),v[a].end(),compare);
    setCount++;
    visited[a] = setCount;
    for(int i : v[a]){
        if(visited[i] == 0){
            dfs(i);
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r;
    fill(visited, visited + 100004, 0);
    for(int i = 0; i < m; i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
        // sort(v[num2].begin(),v[num2].end());
    }
    dfs(r);
    for(int i = 1; i <= n; i++){
        cout << visited[i] << '\n';
    }
    return 0;
}