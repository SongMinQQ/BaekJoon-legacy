#include <bits/stdc++.h>
using namespace std;

int n, cnt;

bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

void primeNum(int a){
    for(int i = a + 1; i <= a * 2; i++){
        if(check(i)) cnt++;
    }
}

int main(){
    while(1){
        cin >> n;
        if(n == 0) break;
        cnt = 0;
        primeNum(n);
        cout << cnt << '\n';
    }
}