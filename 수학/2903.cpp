#include <bits/stdc++.h>
using namespace std;

int n;
long long result;

int main(){
    cin >> n;
    result = pow(2,n) + 1;
    cout << result * result;
    return 0;
}