#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ret, temp1, temp;
int main(){
  cin >> n >> k;
  vector<pair<ll, ll>> v(n);//골동품의 무게, 가치
  vector<ll> vv(k);//가방의 용량
  for(int i = 0; i < n; i++){
    cin >> v[i].first >> v[i].second;
  }
  for(int i = 0; i < k; i++){
    cin >> vv[i];
  }
  sort(v.begin(), v.end());
  sort(vv.begin(), vv.end());
  priority_queue<ll> pq;//가치가 가장 높은 물건을 우선적으로 가방에 넣음
  int j = 0;
  for(int i = 0; i < k; i++){
    /*
    j가 물건의 범위를 벗어나지 않으면서 물건의 무게가 가방의 무게보다 작거나 같으면
    물건의 가치를 priority queue에 넣음
    들어간 물건이 있다면
    priority queue의 top에 있는 물건이 가장 가치가 높다는 뜻
    이걸 결과에 더함
    */
    while(j < n && v[j].first <= vv[i]) pq.push(v[j++].second); 
    if(pq.size()){
      ret+= pq.top();
      pq.pop();
    }
  }
  cout << ret << '\n';
  return 0;
}