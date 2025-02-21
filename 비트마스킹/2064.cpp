#include<bits/stdc++.h>
using namespace std;

int address[1002][4], n, m, mask[4], ipAddress[4];

bool check(int a, int b){
  if(a ^ b) return true;
  else return false;
}

unsigned int fillBitsBelowHighestSet(unsigned int n) {
    // 0이면 처리할 필요가 없으니 그대로 반환(0의 '최상위 비트'는 없음)
    if (n == 0) return 0; 
    
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    // 만약 64비트 정수(uint64_t)라면 추가로 n |= (n >> 32); 도 수행

    return n; 
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    string ip;
    cin >> ip;

    istringstream ipp(ip);
    string num;
    for(int j = 0; j < 4; j++){
      getline(ipp,num, '.');
      address[i][j] = stoi(num);
    }
  }
  int idx = 0;
  for(int i = 0; i < 4; i++){
    bool isFind = false;
    for(int j = 1; j < n; j++){
      if(check(address[j - 1][i], address[j][i])) {
        m = address[j - 1][i] ^ address[j][i];
        m = fillBitsBelowHighestSet(m);
        cout << "m : " << m << '\n';
        isFind = true;
        idx = i;
        break;
      } 
    }
    if(isFind) break;
  }
  for(int i = 0; i < 4; i++){
    if(i != idx && i < idx) mask[i] = 255;
    // else if(i != idx && i > idx) mask[i] = 0;
    else mask[i] = 255 - (255 & m);
  }
  for(int i = 0; i < 4; i++){
    ipAddress[i] = mask[i] & address[0][i];
  }
  cout << ipAddress[0] << '.' << ipAddress[1] << '.' << ipAddress[2] << '.' << ipAddress[3] << '\n';
  cout << mask[0] << '.' << mask[1] << '.' << mask[2] << '.' << mask[3] << '\n';
  return 0;
}