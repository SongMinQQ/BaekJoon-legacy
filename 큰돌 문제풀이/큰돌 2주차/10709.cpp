#include <bits/stdc++.h>
using namespace std;

char a[104][104];
int h, m;
int main(){
    cin >> h >> m;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < h; i++){
        int minute = 0;
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'c') cout << 0 << ' ';
            else if(a[i][j] == '.'){
                if(a[i][j - 1] == 'c'){
                    minute = 1;
                    cout << minute << ' ';
                }
                else{
                    if(minute > 0){
                        minute++;
                        cout << minute << ' ';
                    }
                    else cout << -1 << ' ';
                    
                }
            }
        }
        cout << '\n';
    }
}