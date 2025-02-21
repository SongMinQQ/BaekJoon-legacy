#include<bits/stdc++.h>
using namespace std;

int n, d, p, result;
vector<pair<int, int>> lecture;
priority_queue<int> pq;
bool check[10002];

bool checkSchedule(int idx){
  for(int i = idx; i > 0; i--){
    if(check[i] == false) {
      check[i] = true;
      return true;
    }
  }
  return false;
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> p >> d;
    lecture.push_back({p, d});
  }
  sort(lecture.rbegin(),lecture.rend());

  for(int i = 0; i < n; i++){
    if(checkSchedule(lecture[i].second)){
      pq.push(lecture[i].first);
    }
  }
  while(pq.size()){
    result+=pq.top();
    pq.pop();
  }
  cout << result << '\n';
  return 0;
}