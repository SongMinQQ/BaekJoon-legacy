#include <iostream>
#include <cmath>

using namespace std;

int find_level(int node) {
    int level = 1;
    while (node > (level * (level + 1)) / 2) {
        level++;
    }
    return level;
}

int calculate_distance(int s, int e) {
    if (s == e) {
        return 0;
    }

    int level_s = find_level(s);
    int level_e = find_level(e);

    // 수직 이동 거리 계산
    int vertical_distance = abs(level_s - level_e);

    // 같은 레벨 내에서 수평 이동 거리 계산
    if (level_s == level_e) {
        int start_of_level = (level_s * (level_s - 1)) / 2 + 1;
        return abs((s - start_of_level) - (e - start_of_level));
    }

    // 더 낮은 레벨에서 더 높은 레벨로 이동
    while (level_s != level_e) {
        if (level_s > level_e) {
            s -= level_s;
            level_s--;
        } else {
            e -= level_e;
            level_e--;
        }
        vertical_distance++;
    }

    return vertical_distance;
}

int main() {
    int T, s, e;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> s >> e;
        cout << calculate_distance(s, e) << endl;
    }

    return 0;
}
