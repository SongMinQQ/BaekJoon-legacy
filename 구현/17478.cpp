#include<bits/stdc++.h>
using namespace std;

int n;

string what = "\"����Լ��� ������?\"";
string listen1 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
string listen2 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
string listen3 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"";
string recursive = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";
string rago = "��� �亯�Ͽ���.";

string printUnderline(int cnt){
  string underline = "";
  for(int i = 0; i < cnt; i++){
    underline += "____";
  }
  return underline;
}

void print(int cnt){
  cout << printUnderline(cnt) << what << '\n';
  if(cnt == n){
    cout << printUnderline(cnt) << recursive << '\n' << printUnderline(cnt) << rago << '\n';
    return;
  }
  else{
    cout << printUnderline(cnt) << listen1 << '\n' << printUnderline(cnt) << listen2 << '\n' << printUnderline(cnt) << listen3 << '\n';
    print(cnt + 1);
  }
  
  cout << printUnderline(cnt) << rago << '\n';
  return;
}

int main(){
  cin >> n;
  cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
  print(0);
  return 0;
}