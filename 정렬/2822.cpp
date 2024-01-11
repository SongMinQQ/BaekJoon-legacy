#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
vector<int> v2;
int num, sum = 0;
int main(){
    for(int i = 1; i < 9;i++){
        cin >> num;
        v.push_back(make_pair(num,i));
    }
    sort(v.begin(),v.end());
    for(int i = 3; i < 8; i++){
        sum+=v[i].first;
    }
    cout << sum << '\n';
    for(int i = 3; i < 8; i++){
        v2.push_back(v[i].second);
    }
    sort(v2.begin(), v2.end());
    for(int i = 0; i < 5; i++){
        cout << v2[i] << ' ';
    }
    return 0;
}