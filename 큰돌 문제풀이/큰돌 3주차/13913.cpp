#include <bits/stdc++.h>
using namespace std;

const int MAX = 200004;
int n, k, visited[MAX], cnt[MAX], result;
vector<int> v;
int main(){
    cin >> n >> k;
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == k) {
            result = visited[k];
            break;
        }
        // +1 -1 *2 방향으로 bfs 탐색
        for(int i : {now + 1, now - 1, now * 2}){
            if(0 > i || i >= MAX || visited[i]) continue;
                q.push(i);
                visited[i] = visited[now] + 1;
                cnt[i] = now;
        }
    }
    for(int i = k; i != n; i = cnt[i]){
        v.push_back(i);
    }
    cout << result - 1 << '\n';
    cout << n << ' ';
    if(!v.empty()){
        reverse(v.begin(),v.end());
        for(int i : v) cout << i << ' ';
    }
    return 0;
}