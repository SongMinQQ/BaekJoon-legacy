#include<bits/stdc++.h>
using namespace std;

int t, n; 
long long triangle[500];

int main(){
    triangle[0] = 1; triangle[1] = 1; triangle[2] = 1;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        if(n < 4) cout << 1 << '\n';
        else{
            for(int j = 3; j <= n; j++){
                triangle[j] = triangle[j - 3] + triangle[j - 2];
            }
            cout << triangle[n - 1] << '\n';
        }
    }
    return 0;
}