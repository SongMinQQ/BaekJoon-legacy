#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
long long num, a[1000002];
vector<long long> v;
map<long long, int> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        a[i] = num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        if (m.find(v[i]) != m.end()) {
            continue;
        }
        else {
            m.insert({v[i], cnt});
            cnt++;
        }
    }

    for(int i = 0; i < v.size(); i++){
        auto it = m.find(a[i]);
        cout << it->second << ' ';
    }
    return 0;
}