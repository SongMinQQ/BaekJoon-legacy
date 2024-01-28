#include <bits/stdc++.h>
using namespace std;

int n, c, num;
unordered_map<int, pair<int, int>> m;

bool cmp (const pair<int,pair<int,int>>& a, const pair<int,pair<int, int>>& b){
    if(a.second.first == b.second.first) return a.second.second < b. second.second;
    return a.second.first > b.second.first;
}
int main(){
    cin >> n >> c;
    int order = 0;
    for(int i = 0; i < n; i++){
        cin >> num;
        if (m.find(num) == m.end())
            m[num] = {1, order++}; // 숫자가 처음 나타나면 {빈도수, 입력 순서} 저장
        else
            m[num].first++; // 숫자의 빈도수 증가
    }
    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].second.first; j++ ){
            cout << v[i].first << ' ';
        }
    }
    return 0;
}