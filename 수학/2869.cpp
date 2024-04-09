#include <bits/stdc++.h>
using namespace std;

int a, b, v, result;

int main(){
    cin >> a >> b >> v;
    result = (v - a) / (a - b);
    if((v-a) % (a-b) != 0) result += 2;
    else result +=1;
    cout << result;
    return 0;
}