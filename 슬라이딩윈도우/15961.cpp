#include<bits/stdc++.h>
using namespace std;

int n, d, k, c, result;
int check[3002];

int getMaxResult(){
  
  int cnt = 0;
  for(int i = 1; i <= d; i++){
    if(check[i] > 0) cnt++;
  }
  return cnt;
}
int main(){
  cin >> n >> d >> k >> c;
  int *sushi = new int[n];
  for(int i = 0; i < n; i++){
    cin >> sushi[i];
  }
  //여기서 result의 초기값을 세팅했음
  for(int i = 0; i < k; i++){
    check[sushi[i]]++;
    result = max(result, getMaxResult());
    check[c]++;
  }
  int checker = result;
  
  for(int i = 0; i < n; i++){
    if(check[sushi[(i + k) % n]] == 0){
      check[sushi[(i + k) % n]]++; 
      checker++;
    }
    else if(check[sushi[(i + k) % n]] > 0) check[sushi[(i + k) % n]]++;
    check[sushi[i]]--;
    if(check[sushi[i]] == 0) checker--;
    if(check[c] == 0) result = max(result, checker + 1);
    else result = max(result, checker);
  }
  cout << result;
  return 0;
}