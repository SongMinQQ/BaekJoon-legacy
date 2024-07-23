#include <bits/stdc++.h>
using namespace std;

int a[102];
int b, c, n, cnt = 0;
int main(){
    fill(begin(a), end(a), 2);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b >> c;
        if(a[b] == 2) {
            a[b] = c;
        }
        else {
            if(a[b] == c) {
                continue;
                }
            else{
                a[b] = c;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}