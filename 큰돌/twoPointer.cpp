#include<bits/stdc++.h>
using namespace std;

int n, arr[10000], x, point1, point2, cnt;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(&arr[0], &arr[n]);
  cin >> x;
  point1 = 0, point2 = n - 1;
  while(point1 < point2){
    int sum = arr[point1] + arr[point2];
    if(sum == x){
      cnt++;
      // point1++;
      point2--;
    }
    if(sum > x) point2--;
    if(sum < x) point1++;
  }
  cout << cnt << '\n';
  return 0;
}