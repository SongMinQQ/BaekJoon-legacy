#include<bits/stdc++.h>
using namespace std;

int n;
long long num, result;
stack<long long> s;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    //입력된 숫자가 이전값보다 크거나 같은 경우(오름차순)
    while(s.size() && s.top() <= num){
      s.pop();
    }
    //작은 수일경우(내림차순)
    if(s.size()) result+= s.size();
    s.push(num);
  }
  cout << result;
  /*

  6
  10
  3
  7
  4
  12
  2
  */
  return 0;
}