#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int a[52][52], n, l, r;
bool visited[52][52];
vector<vector<pair<int, int>>> unions;
vector<int> unionPops;

void calculateAndInsertNum(vector<pair<int, int>>& unionCountries, int totalPop) {
    int moveNum = totalPop / unionCountries.size();
    for (auto& country : unionCountries) {
        a[country.first][country.second] = moveNum;
    }
}

void bfs(int s, int b){
    vector<pair<int, int>> unionCountries;
    int total = 0;
    visited[s][b] = 1;
    queue<pair<int, int>> q;
    q.push({s, b});
    unionCountries.push_back({s, b});
    total += a[s][b];
    while(q.size()){
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(visited[ny][nx]) continue;
            if(abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r ){
                visited[ny][nx] = 1;
                q.push({ny, nx});
                unionCountries.push_back({ny, nx});
                total += a[ny][nx];
            }
        }
    }
    if (unionCountries.size() > 1) {
        unions.push_back(unionCountries);
        unionPops.push_back(total);
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int result = 0;
    while(true){
        fill(&visited[0][0], &visited[51][52], 0);
        unions.clear();
        unionPops.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]) {
                    bfs(i,j);
                }
            }
        }
        if (unions.empty()) break;
        for (size_t i = 0; i < unions.size(); i++) {
            calculateAndInsertNum(unions[i], unionPops[i]);
        }
        result++;
    }
    cout << result;
}
