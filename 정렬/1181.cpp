#include <bits/stdc++.h>
using namespace std;

map<string,int> m;
int n;

static bool comp(pair<string, int>& a, pair<string, int>& b){
    if(a.first.length() == b.first.length()) return a.first < b.first;
	return a.first.length() < b.first.length();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        if(m.find(line) == m.end()){
            m.insert({line, line.size()});
        }
        else continue;
    }
    vector<pair<string, int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(), comp);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << '\n';
    }
    return 0;
}