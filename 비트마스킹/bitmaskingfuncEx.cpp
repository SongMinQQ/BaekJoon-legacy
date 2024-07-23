#include <bits/stdc++.h>
using namespace std;

const int n = 4;
string a[4] = {"사과", "딸기", "포도", "배"};
void go(int num){
    string ret = "";
    for(int i = 0; i < 4; i++){
        if(num & (1 << i)) ret += a[i] + " ";
    }
    cout << ret << '\n';
    return;
}
int main(){
    for(int i = 0; i < n; i++){
        go(1 | (1 << i)); //i번째 idx를 매개변수로 넘김
        /*
        0 0 0 1
        0 0 1 1
        0 1 0 1
        1 0 0 1
        */
    }
    return 0;
}