#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000003];
int main(){
    a[1] = 1;
    a[2] = 2;
    for(int i = 3; i <= 1000000; i++){
        a[i] = ((a[i - 1] % 15746) + (a[i - 2] % 15746)) % 15746;
    }
    cin >> n;
    cout << a[n];
    return 0;
}