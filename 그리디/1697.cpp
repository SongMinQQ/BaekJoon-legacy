#include <bits/stdc++.h>
using namespace std;

int n, k, divideNum, modNum, result = 0;

int main(){
    cin >> n >> k;
    divideNum = k / n;
    modNum = (n * divideNum) % k;
    cout << divideNum << ' ' << modNum << '\n';
    if(modNum == 0){
        cout << divideNum;
        return 0;
    }
    if(modNum >= k / 2){
        divideNum++;
        result += divideNum;
        n *= divideNum;
        for(int i = n; i <= k; i--){
            result += 1;
        }
    }
    else{
        result += divideNum;
        for(int i = n; i <= k; i++){
            result += 1;
        }
    }
    cout << result;
}