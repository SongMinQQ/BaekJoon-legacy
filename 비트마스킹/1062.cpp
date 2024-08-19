#include <bits/stdc++.h>
using namespace std;

int n, m, words[51];
string s;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(char str : s){
            words[i] |= (1 << (str - 'a'));
        }
    }
    //더 공부하고 풀것
}