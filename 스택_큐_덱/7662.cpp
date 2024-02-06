#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> pq;
priority_queue<long long, vector<long long>, greater<long long>> pq2;
unordered_map<long long, int> setCount; 

void adjust() {
    while (!pq.empty() && setCount[pq.top()] == 0) {
        pq.pop();
    }
    while (!pq2.empty() && setCount[pq2.top()] == 0) {
        pq2.pop();
    }
}

void clear() {
    while (!pq.empty()) pq.pop();
    while (!pq2.empty()) pq2.pop();
    setCount.clear();
}

int main() {
    int t, k;
    cin >> t;
    while (t--) {
        cin >> k;
        clear();
        for (int i = 0; i < k; i++) {
            char cmd;
            long long num;
            cin >> cmd >> num;
            if (cmd == 'I') {
                pq.push(num);
                pq2.push(num);
                setCount[num]++;
            } else if (cmd == 'D') {
                adjust();
                if (num == 1 && !pq.empty()) {
                    setCount[pq.top()]--;
                    pq.pop(); 
                } else if (num == -1 && !pq2.empty()) { 
                    setCount[pq2.top()]--; 
                    pq2.pop(); 
                }
            }
        }
        adjust();
        if (pq.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            cout << pq.top() << ' ' << pq2.top() << '\n';
        }
    }
    return 0;
}
