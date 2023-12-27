#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<pair<int, string>> v;

bool compare(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
}
int main(){
    int a, num;
    string name;

    cin >> a;

    for(int i = 0; i < a; i++){
        cin >> num >> name;
        v.push_back(make_pair(num, name));
    }
    stable_sort(v.begin(), v.end(), compare);

    for(int i = 0; i < a; i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}