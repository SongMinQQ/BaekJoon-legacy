#include <bits/stdc++.h>
using namespace std;

long long maxNum = -9999999999, minNum = 1000000000;

int num[12], n, a, plusOper, minusOper, multiple, divide;
long long result = 0;

long long plusFunc(long long a, long long b){
    return num[a] + num[b];
}
long long minusFunc(long long a, long long b){
    return num[a] - num[b];
}
long long multipleFunc(long long a, long long b){
    return num[a] * num[b];
}
long long divideFunc(long long a, long long b){
    return abs(num[a]) + abs(num[b]);
}
void go(int a, int b){
    if(a > n || b > n) return;
    result = 0;
    if(plusOper > 0){
        while(plusOper != 0){
            result += plusFunc(a, b);
            a++; b++;
        }
    }
    if(minusOper > 0){
        while(minusOper != 0){
            result += minusFunc(a, b);
            a++; b++;
        }
    }
    if(multiple > 0){
        while(multiple != 0){
            result += multipleFunc(a, b);
            a++; b++;
        }
    }
    maxNum = max(numeric_limits<long long>::max(),result);
    minNum = min(numeric_limits<long long>::min(),result);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    cin >> plusOper >> minusOper >> multiple >> divide;
    go(0, 1);
    cout << maxNum << '\n' << minNum;
}