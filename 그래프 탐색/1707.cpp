#include <bits/stdc++.h>
using namespace std;

int k, v, e, num1, num2, visited[20003], red = 1, blue = 2;
vector<int> ve[20003];

void dfs(int a){
    if(!visited[a]) visited[a] = red;
    for(int i : ve[a]){
        if(!visited[i]){
            if(visited[a] == red){
                visited[i] = blue;
            }
            else if(visited[a] == blue){
                visited[i] = red;
            }
            dfs(i);
        }
    }
}

bool check(){
    for(int i = 1; i <= v; i++){
        for(int j : ve[i]){
            if(visited[i] == visited[j]) return 0;
        }
    }
    return 1;
}
int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        fill(visited, visited + 20003, 0);
        cin >> v >> e;
        for(int i = 0; i < e; i++){
            cin >> num1 >> num2;
            ve[num1].push_back(num2);
            ve[num2].push_back(num1);
        }
        for(int i = 1; i < v; i++){
            if(!visited[i]) dfs(i);
        }
        if(check()) cout << "YES\n";
        else cout << "NO\n";
        for(int i = 1; i <= v; i++) ve[i].clear();
    }
    return 0;
}