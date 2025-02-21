#include <bits/stdc++.h>
using namespace std;

int n, m, words[51];
string s;
/*
idx부터 순차적으로 탐색, 배운 단어를 카운트할 learn, 현재 idx, 배울수 있는 단어의 수 word
일단 a n t i c 를 못배우면 바로 나가리임
현재 배운 알파벳을 비트로 딱 그만큼 켜려면 어케 해야하는지?
시간복잡도 2^26승 하지만 머리가 안돌아감 빙빙빙
*/
int go(int idx, int word, int learn){
    if(word < 0) return 0;

}
int main(){
    // cout << 'n' - 'a' << ' ' <<'t' - 'a' << ' ' << 'i' - 'a' << ' ' << 'c' - 'a' << '\n';
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(char str : s){
            words[i] |= (1 << (str - 'a'));
        }
    }
    cout << go(0, m, 0) << '\n';
    return 0;
    //더 공부하고 풀것
}