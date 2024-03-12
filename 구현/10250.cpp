#include <bits/stdc++.h>
using namespace std;

int t, h, w, n;

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> h >> w >> n;
        int ho = 101;
        int num = 1;
        for(int j = 0; j < w; j++){
            for(int k = 0; k < h; k++){
                ho += 100;
                n--;
                if(n == 0) break;
            }
            if(n == 0) break;
            ho = 101 + num;
            num++;
        }
        cout << ho - 100 <<'\n';
    }
    return 0;
}