#include <bits/stdc++.h>
using namespace std;

int f(int a1, int a0, int n){
    return (a1 * n) + a0;
}
int o(int c, int n){
    return c * n;
}
int main(){
    int a1, a0, c, n0;

    cin >> a1 >> a0;

    cin >> c;
    
    cin >> n0;
    bool isBigO = true;
    for (int n = n0; n <= 100; ++n) { // n0부터 100까지의 범위에서 확인
        if (f(a1, a0, n) > o(c, n)) { // f(n)이 c * n보다 큰 경우
            isBigO = false;
            break;
        }
    }

    cout << (isBigO ? 1 : 0);
    return 0;
}