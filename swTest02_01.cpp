#include <bits/stdc++.h>
using namespace std;

int t, n, print = 1;
vector<tuple<int, int, int>> agents;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        agents.clear();
        agents.resize(n);

        vector<int> shared(n, -1);
        int totalLoss = 0, sum = 0;
        array<int, 3> abilityCount = {0, 0, 0};

        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            agents[i] = make_tuple(a, b, c);
            sum += a + b + c;
        }

        for (int i = 0; i < n; i++) {
            int a, b, c;
            tie(a, b, c) = agents[i];
            int maxAbility = max({a, b, c});
            sum -= maxAbility; 

            if (b + c <= a + c && b + c <= a + b) {
                shared[i] = 0;
                abilityCount[0]++;
            } else if (a + c <= b + c && a + c <= a + b) {
                shared[i] = 1;
                abilityCount[1]++;
            } else {
                shared[i] = 2;
                abilityCount[2]++;
            }
        }

        for (int i = 0; i < n && (*min_element(abilityCount.begin(), abilityCount.end()) == 0); i++) {
            int& currAbility = shared[i];
            if (abilityCount[currAbility] > 1) {
                for (int j = 0; j < 3; j++) {
                    if (abilityCount[j] == 0) {
                        abilityCount[currAbility]--;
                        abilityCount[j]++;
                        currAbility = j;
                        break;
                    }
                }
            }
        }

        if (*min_element(abilityCount.begin(), abilityCount.end()) == 0) {
            totalLoss = -1;
        } else {
            for (int i = 0; i < n; i++) {
                int a, b, c;
                tie(a, b, c) = agents[i];

                if (shared[i] == 0) totalLoss += b + c;
                else if (shared[i] == 1) totalLoss += a + c;
                else totalLoss += a + b;
            }
        }

        if (totalLoss == -1) {
            cout << '#' << print << ' ' << -1 << '\n';
        } else {
            cout << '#' << print << ' ' << max(totalLoss, sum) << '\n';
        }
        print++;
    }
    return 0;
}
