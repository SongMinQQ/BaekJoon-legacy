#include <bits/stdc++.h>
using namespace std;

int n, m, num;
vector<pair<int, int>> numV; // 숫자 값과 해당 숫자의 사용 여부를 저장합니다.
vector<int> v;

void makeVector(int index) {
    if (v.size() == m) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = index; i < numV.size(); i++) {
        if (numV[i].second == 0) { // 현재 숫자가 아직 사용되지 않았다면
            numV[i].second = 1; // 사용되었다고 표시합니다.
            v.push_back(numV[i].first);
            makeVector(i + 1);
            v.pop_back();
            numV[i].second = 0; // 숫자 사용을 취소합니다.
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num;
        bool found = false;
        // 이미 리스트에 같은 숫자가 있는지 확인합니다.
        for (auto &p : numV) {
            if (p.first == num) {
                found = true;
                break;
            }
        }
        // 같은 숫자가 없을 경우에만 추가합니다.
        if (!found) {
            numV.push_back({num, 0});
        }
    }
    sort(numV.begin(), numV.end());
    makeVector(0);
    return 0;
}
