#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
vector<int> result;
int fib(int n){
    
    if(n == 1 || n == 2) {cnt++; return 1;}
    else {
        return (fib(n - 1) + fib(n - 2));
    }
}
int fibonacci(int n) {
    if (n <= 1) return n;
    int dp[n+1];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        cnt++;
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    cin >> n;
    fib(n);
    result.push_back(cnt);
    cnt = 0;
    fibonacci(n);
    result.push_back(cnt);
    for(int i : result){
        cout << i << ' ';
    }
    return 0;
}