#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> operAtor;
string s;
int n, result = -987654321;

int oper(char a, int b, int c){
    if(a == '+') return b + c;
    if(a == '-') return b - c;
    if(a == '*') return b * c;
}

void go(int here, int number){
    if(here == num.size() -1){
        result = max(result, number);
        return;
    }
    go(here + 1, oper(operAtor[here], number, num[here + 1]));
    if(here + 2 <= num.size() -1){
        int a = oper(operAtor[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, oper(operAtor[here], number, a));
    }
    return;
}

int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0)num.push_back(s[i] - '0');
        else operAtor.push_back(s[i]);
    }
    go(0, num[0]);
    cout << result;
}