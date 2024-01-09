#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> findInfo(int node) {
    int level = 1;

    while (node > (level * (level + 1)) / 2) {
        ++level;
    }

    int indexLevel = node - (level * (level - 1)) / 2;
    return make_pair(level, indexLevel);
}

int calculate_node(int level, int indexLevel) {
    return (level * (level - 1)) / 2 + indexLevel;
}

int bfs(int start, int end) {
    if (start == end) {
        return 0;
    }

    pair<int, int> start_info = findInfo(start);
    pair<int, int> end_info = findInfo(end);

    vector<bool> visited(10001, false); 
    queue<pair<int, int>> q;

    q.push(make_pair(start, 0));
    visited[start] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int currentNodeNum = current.first;
        int distance = current.second;

        pair<int, int> currentNode = findInfo(currentNodeNum);

        vector<int> possible;
        if (currentNode.second > 1) {
            int newNode = calculate_node(currentNode.first, currentNode.second - 1);
            if (newNode <= 10000) possible.push_back(newNode);
        }
        if (currentNode.second < currentNode.first) {
            int newNode = calculate_node(currentNode.first, currentNode.second + 1);
            if (newNode <= 10000) possible.push_back(newNode);
        }
        if (currentNode.second != 1) {
            int newNode = calculate_node(currentNode.first - 1, currentNode.second - 1);
            if (newNode > 0) possible.push_back(newNode);
        }
        if (currentNode.second != currentNode.first) {
            int newNode = calculate_node(currentNode.first - 1, currentNode.second);
            if (newNode > 0) possible.push_back(newNode);
        }
        if (currentNode.first != 1) {
            int newNode = calculate_node(currentNode.first + 1, currentNode.second);
            if (newNode <= 10000) possible.push_back(newNode);
        }
        if (currentNode.first != 1) {
            int newNode = calculate_node(currentNode.first + 1, currentNode.second + 1);
            if (newNode <= 10000) possible.push_back(newNode);
        }


        for (int next_node : possible) {
            if (next_node == end) {
                return distance + 1;
            }
            if (!visited[next_node]) {
                q.push(make_pair(next_node, distance + 1));
                visited[next_node] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, s, e;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s >> e;
        cout << '#' << i + 1 << ' ' <<  bfs(s, e) << '\n';
    }
    return 0;
}
