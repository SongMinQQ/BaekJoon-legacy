#include <bits/stdc++.h>
using namespace std;

int n, m, j, l, r, temp, ret;

int main(){
    cin >> n >> m >> j;
    l = 1;
    for(int i = 0; i < j; i++){
        r = l + m - 1;
        cin >> temp;
        if(temp >= l && temp <= r) continue; //만약 사과가 바구니에 걸칠 경우 continue
        else{
            if(temp < l){
                ret += (l - temp);
                l = temp;
            }
            else{
                l += (temp - r);
                ret += (temp - r);
            }
        }
    }
    cout << ret << '\n';
}