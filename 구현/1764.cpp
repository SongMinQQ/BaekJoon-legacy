#include <bits/stdc++.h>
using namespace std;

string a;
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    map<string, int> name;
    vector<string> result;
    for(int i = 0; i < n; i++){
        cin >> a;
        name[a]++;
    }
    for(int i = 0; i < m; i++){
        cin >> a;
        name[a]++;
        if(name[a] > 1) result.push_back(a);
    }
    
    sort(result.begin(),result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << '\n';
    }
    return 0;
}