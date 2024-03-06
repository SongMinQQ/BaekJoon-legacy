#include <bits/stdc++.h>
using namespace std;

vector<int> v[100002];
int n, num1, num2, parentNode[100002];
bool visited[100002];

void dfs(int a){
    visited[a] = 1;
    for(int i : v[a]){
        if(!visited[i]){
            parentNode[i] = a;
            dfs(i);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    dfs(1);
    for(int i = 2; i <= n; i++){
        cout << parentNode[i] << '\n';
    }
}