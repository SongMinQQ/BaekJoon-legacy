#include <bits/stdc++.h>
using namespace std;

int n, m, num;
vector<int> numV;
vector<int> v;
// bool visited[10];
void makeVector(int a, int index) {
    if (v.size() == m) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for (int i = a; i < numV.size(); i++) {
        // cout <<"index : " << index << " tmp : " << tmp << '\n';
        if(tmp != numV[i]){
            v.push_back(numV[i]);
            // visited[i] = 1;
            tmp = numV[i];
            makeVector(i, index + 1);
            // visited[i] = 0;
            v.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        numV.push_back(num);
    }
    sort(numV.begin(), numV.end());
    makeVector(0, 0);
    return 0;
}
