#include <bits/stdc++.h>
using namespace std;

string a;
int b;
long long result = 0;

int main(){
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        int num = (int)a[i];
        long long num2 = pow(b, (a.size() - 1) - i);
        // cout << num2 << '\n';
        if((num - 55) >= 10){
            result += (num - 55) * num2;
        }
        else result += (num - '0')* num2;
    }

    cout << result << '\n';
    return 0;
}