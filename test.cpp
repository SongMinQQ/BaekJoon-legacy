#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main(){
  for(int i = 0; i < 3; i++){
    v.push_back(i);
  }
  v.pop_back();
  for(int i : v){
    cout << i << '\n';
  }
  return 0;
}