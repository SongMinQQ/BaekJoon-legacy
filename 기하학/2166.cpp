#include <bits/stdc++.h>
using namespace std;
vector<double> x;
vector<double> y;
double a, b, n, result = 0.0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int j = (i + 1) % (int)n;
        result += x[i] * y[j] - x[j] * y[i];
        cnt++;
    }
    result = abs(result) / 2.0;
    cout << fixed << setprecision(1) << result;
}