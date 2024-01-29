#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
int n, a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        int result2 = 0, result5 = 0;
        for(int j = 2; j <= a; j*=2){
            result2 += a / j;
        }
        for(int j = 5; j <= a; j*=5){
            result5 += a / j;
        }
        cout << min(result2, result5) << '\n';
    }
    return 0;
}