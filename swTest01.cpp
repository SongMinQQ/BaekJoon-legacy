#include <bits/stdc++.h>
using namespace std;

int find_level(int node) {
    int level = 1;
    while (node > level) {
        node -= level;
        level++;
    }
    return level;
}

int find_distance(int s, int e) {
    if(s == e) {
        return 0;
    }

    int level_s = find_level(s);
    int level_e = find_level(e);

    int index_s = s - (level_s * (level_s - 1)) / 2;
    int index_e = e - (level_e * (level_e - 1)) / 2;
    
    if (level_s == level_e) {
        return abs(index_s - index_e);
    }

    int vertical_distance = abs(level_s - level_e);
    int horizontal_distance = 0;
    if (level_s > level_e) {
        s -= ((level_s - 1) * level_s) / 2;
        e -= ((level_e - 1) * level_e) / 2;
        horizontal_distance = abs(s - e);
    } else {
        swap(s, e);
        swap(level_s, level_e);
        s -= ((level_s - 1) * level_s) / 2;
        e -= ((level_e - 1) * level_e) / 2;
        horizontal_distance = abs(s - e);
    }

    return vertical_distance + max(horizontal_distance - vertical_distance, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, s, e;
    cin >> T;
    
    for (int i = 0; i < T; ++i) {
        cin >> s >> e;
        cout << '#' << i+1 << ' ' << find_distance(s, e) << '\n';
    }
    
    return 0;
}
