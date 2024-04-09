#include <bits/stdc++.h>
using namespace std;

int n;
long long result = 1;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    cout << result;
    return 0;
}