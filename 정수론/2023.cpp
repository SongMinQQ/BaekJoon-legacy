#include <iostream>
#include <cmath>
using namespace std;

int N;
int first[4] = { 2, 3, 5, 7 };

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int number, int depth) {
    if (depth == N) {
        cout << number << endl;
        return;
    }

    for (int i = 1; i <= 9; i += 2) {
        int newNumber = number * 10 + i;
        if (isPrime(newNumber)) {
            dfs(newNumber, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < 4; i++) {
        dfs(first[i], 1);
    }

    return 0;
}
