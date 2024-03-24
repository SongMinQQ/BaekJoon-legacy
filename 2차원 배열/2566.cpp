#include <bits/stdc++.h>
using namespace std;

int a[10][10], maxNum = 0, y, x;

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> a[i][j];
            if(a[i][j] > maxNum){
                maxNum = a[i][j];
                y = i;
                x = j;
            }
        }
    }
    cout << maxNum << '\n' << y + 1 << ' ' << x + 1;
    return 0;
}