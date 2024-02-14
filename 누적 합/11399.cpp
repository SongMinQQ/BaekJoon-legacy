#include <bits/stdc++.h>
using namespace std;

int n, p[1004], sum[1004], result = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sum[0] = 0;

    sort(p, p + n);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + p[i - 1];
        result += sum[i];
    }
    cout << result;
    return 0;
}