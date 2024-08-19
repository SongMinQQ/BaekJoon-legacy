#include<bits/stdc++.h>
using namespace std;

int x, cnt = 1;

int main(){
    cin >> x;
    while(x != 1){
        if(x & 1) cnt++;
        x /= 2;
    }
    cout << cnt << '\n';
    return 0;
}