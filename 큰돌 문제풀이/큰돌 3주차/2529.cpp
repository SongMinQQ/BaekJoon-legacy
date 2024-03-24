#include <bits/stdc++.h>
using namespace std;

int k;
char sign;
bool visited[10];
vector<char> v;
vector<string> s;

bool isRight(char x, char y, char op){
    if(x < y && op == '<') return true;
    if(x > y && op == '>') return true;
    return false;
}
void go(int num, string ret){
    if(num == k + 1){
        s.push_back(ret);
    }
    for(int i = 0; i <= 9; i++){
        if(visited[i]) continue;
        if(num == 0 || isRight(ret[num - 1], i + '0', v[num - 1])){
            visited[i] = 1;
            go(num + 1, ret + to_string(i));
            visited[i] = 0;
        }
    }
    return;
}
int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> sign;
        v.push_back(sign);
    }
    go(0, "");
    sort(s.begin(), s.end());
    cout << s[s.size() - 1] << '\n' << s[0] << '\n';
}