#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int a, b, c;
    cin >> a;

    for(int i = 0; i < a; i++){
        cin >> b >> c;
        v.push_back(make_pair(b, c));
    }
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < a; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
}