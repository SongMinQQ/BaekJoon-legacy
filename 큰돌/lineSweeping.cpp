#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
P L[1000004];
int n, from, to, l, r, ret;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> from >> to;
    L[i] = P(from, to);
  }
  sort(L, L + n);
  l = L[0].first; r = L[0].second;
  for(int i = 1; i < n; i++){
    //새로운 구간일 경우엔 결과를 더하고 시작, 끝지점 새롭게 정의
    if(r < L[i].first){
      ret += (r - l);
      l = L[i].first;
      r = L[i].second;
    }
    //구간이 겹치지만 끝지점이 다를 경우엔 끝지점만 새롭게 정의
    else if(L[i].first <= r && L[i].second >= r){
      r = L[i].second;
    }
  }
}