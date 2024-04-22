#include <bits/stdc++.h>
using namespace std;

int n, k, num;
vector<int> v;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << v[n - k];
    return 0;
}