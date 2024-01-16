#include <bits/stdc++.h>
using namespace std;
int n, k;

int ehanggyesu(int a, int b){
    if(b == 0 || a == b) return 1;
    return ehanggyesu(a-1, b) + ehanggyesu(a-1, b-1);
}
int main(){
    cin >> n >> k;
    cout << ehanggyesu(n, k);
}