#include <bits/stdc++.h>
using namespace std;

int t;
long long n;
string dongwoo = "kidw0124";
string jaewoo = "eoaud0108";
string simulate(vector<int>& pos, int turn) {
    if (pos.empty()) return turn % 2 == 0 ? dongwoo : jaewoo;
    
    string curr = turn % 2 == 1 ? dongwoo : jaewoo;
    
    for (size_t i = 0; i < pos.size(); ++i) {
        int move_size = turn == 1 ? 1 : i + 2;
        
        if (i + move_size <= pos.size()) {
            vector<int> next_pos = pos;
            next_pos.erase(next_pos.begin() + i, next_pos.begin() + i + move_size);
            
            if (!next_pos.empty()) {
                size_t mid = i < next_pos.size() ? i : next_pos.size() - 1;
                vector<int> p1(next_pos.begin(), next_pos.begin() + mid);
                vector<int> p2(next_pos.begin() + mid, next_pos.end());
                
                next_pos = p1.size() < p2.size() ? p2 : (p1.size() > p2.size() ? p1 : next_pos);
            }
            
            if (simulate(next_pos, turn + 1) == curr) {
                return curr;
            }
        }
    }
    
    return turn % 2 == 0 ? dongwoo : jaewoo;
}

int main() {
    cin >> t;
        for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> pos(n, 1);
        string winner = simulate(pos, 1);
        cout << winner << '\n';
        pos.clear();
    }
    return 0;
}
