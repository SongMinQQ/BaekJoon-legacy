#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n, k, visited[100002], cnt[100001];

int main(){
    cin >> n >> k;
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        // +1 -1 *2 방향으로 bfs 탐색
        for(int i : {now + 1, now - 1, now * 2}){
            if(0 <= i && i <= MAX){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = visited[now] + 1;
                    cnt[i] += cnt[now];
                }
                else if(visited[i] == visited[now] + 1){
                    cnt[i] += cnt[now];
                }
            }
        }
    }
    cout << visited[k] - 1 << '\n';
    return 0;
}