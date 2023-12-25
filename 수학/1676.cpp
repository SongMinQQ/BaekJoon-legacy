#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    int count = 0;
    for (int i = 5; num / i >= 1; i *= 5) {
        count += num / i;
    }

    cout << count;
    return 0;
}
