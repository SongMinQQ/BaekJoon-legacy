#include <iostream>
#include <vector>
using namespace std;

// 11의 배수인지 확인하는 함수
bool isMultipleOfEleven(const string& num) {
    long long sumOdd = 0, sumEven = 0;
    for (int i = 0; i < num.length(); ++i) {
        if (i % 2 == 0) sumEven += num[i] - '0';
        else sumOdd += num[i] - '0';
    }
    return (sumEven - sumOdd) % 11 == 0;
}

// 팰린드롬인지 확인하는 함수
bool isPalindrome(const string& num) {
    int left = 0, right = num.length() - 1;
    while (left < right) {
        if (num[left] != num[right]) return false;
        left++; right--;
    }
    return true;
}

void findPalindromeNumbers(string& current, int n, bool& found) {
    if (found) return;
    if (current.size() == n) {
        if (isMultipleOfEleven(current) && isPalindrome(current)) {
            cout << current << endl;
            found = true;
        }
        return;
    }

    for (char digit = '0'; digit <= '9'; ++digit) {
        if (current.empty() && digit == '0' && n != 1) continue; // 첫 번째 자리수가 0인 경우를 제외
        current.push_back(digit);
        findPalindromeNumbers(current, n, found);
        if (found) return;
        current.pop_back();
    }
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        string current = "";
        bool found = false;
        findPalindromeNumbers(current, N, found);
        if (!found) cout << "-1" << endl;
    }
    return 0;
}
