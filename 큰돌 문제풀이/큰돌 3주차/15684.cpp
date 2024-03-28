#include <bits/stdc++.h>
using namespace std;

int n, m, h, ladders[32][12], num1, num2, destination, ret = 99999999;

//구현해야 할 것들
//사다리 끝까지 도달했는지
//i => i까지 제대로 도달했는지
//사다리 추가 로직
//사다리가 4개이상 추가될경우 -1
//사다리는 1개 -> 2개 -> 3개 순으로 완전탐색
//다 했는데 불가능할경우 -1
bool dfs(){
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(ladders[j][start])start++;
            else if(ladders[j][start - 1])start--;
        }
        if(start != i) return false;
    }
    return true;
}

void calculate(int here, int cnt){ 
    if(cnt > 3 || cnt >= ret) return;
    if(dfs()){
        ret = min(ret, cnt); return;
    }
    for(int i = here; i <= h; i++){
        for(int j = 1; j < n; j++){
            if(ladders[i][j] || ladders[i][j - 1] || ladders[i][j + 1]) continue;
            ladders[i][j] = 1;
            calculate(i, cnt + 1);
            ladders[i][j] = 0;
        }
    }
}
int main(){
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        cin >> num1 >> num2;
        ladders[num1][num2] = 1;
    }
    calculate(1, 0);
    cout << ((ret == 99999999) ? -1 : ret);
    return 0;
}