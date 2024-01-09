#include <bits/stdc++.h>
using namespace std;

int n, m, sum = 0, v[15001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count = 0;
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    if(m > 200000) cout << 0 << '\n';
    else {
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(v[i] + v[j] == m) count++;
            }
        }
    }
    cout << count;
}