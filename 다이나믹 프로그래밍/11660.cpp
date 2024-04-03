#include <bits/stdc++.h>
using namespace std;

long long a[1026][1026];
int n, m, x1, y, x2, y2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for(int i = 0; i < m; i++){
        cin >> x1 >> y >> x2 >> y2;
        cout << a[x2][y2] - a[x2][y - 1] - a[x1 - 1][y2] + a[x1 - 1][y - 1] << '\n';
    }
    return 0;
}