#include <bits/stdc++.h>
using namespace std;

long long combination(int n, int r) {
    long long result = 1;
    for (int i = 1; i <= r; ++i) {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << combination(m, n) << '\n';
    }
}
