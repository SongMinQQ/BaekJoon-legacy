#include <bits/stdc++.h>
using namespace std;

int n, l, a[102][102], b[102][102], result = 0, cnt;

void cal(int a[102][102]){
    for(int i = 0; i < n; i++){
        cnt = 1;
        int j;
        for(j = 0; j < n - 1; j++){
            if(a[i][j] == a[i][j + 1]) cnt++;
            else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
            else if(a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = 1 - l;
            else break;
        }
        if(j == n - 1 && cnt >= 0) {
            cout << i << " good\n" ;
            result++;
        }
    }
}

int main(){
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
    cal(a);
    cal(b);
    cout << result << '\n';
    return 0;
}