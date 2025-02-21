#include<bits/stdc++.h>
using namespace std;

int n, nums[] = {1, 2, 3, 4};

void solve(int cnt, int visited, int value){
  if(cnt == 4) {
    cout << value << '\n';
  }
  // int ret = 0;
  for(int i = 0; i < n; i++){
    if(visited & (1 << i)) continue;
    solve(cnt + 1, visited | (1 << i), value * 10 + nums[i]);
  }
}
int main(){
  cin >> n;
  solve(0, 0, 0);
  return 0;
}