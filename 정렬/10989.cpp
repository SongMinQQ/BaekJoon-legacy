#include <bits/stdc++.h>
using namespace std;

int n, num, result[10001] = {0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        result[num] += 1;
    }
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < result[i]; j++) {
            cout << i << '\n';
        }
    }
    return 0;
}