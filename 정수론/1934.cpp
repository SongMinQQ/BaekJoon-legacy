#include <bits/stdc++.h>
using namespace std;

long long int gcd(int a, int b){
    if(a == 0) return b;
    return(gcd(b % a, a));
}
long long int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}
int main(){
    long long int a, b;
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
    cin >> a >> b;
    cout << lcm(a, b) << '\n';
    }
    return 0;
}