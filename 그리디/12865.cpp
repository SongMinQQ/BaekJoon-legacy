#include<bits/stdc++.h>
using namespace std;

int n, k, result;
int main(){
  cin >> n >> k;
  vector<pair<int,int>> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  /*
  v.first의 합이 k가 되는 조합을 모두 구할경우 k미만의 경우의 수 중 최대값을 못구하는 반례
  입력을 받으면서 동시에? 어케함
  이전값 재사용을 해야할듯
  는 할줄 모르므로 다음에 풀자
  */
  return 0;
}