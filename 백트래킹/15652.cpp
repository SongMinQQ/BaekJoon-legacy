#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void makeVector(int a){
    if(v.size() == m) {
        for(int i : v){
                cout << i << ' ';
            }
            cout << '\n';
        return;
    }
    for(int i = a; i <= n; i++){
        v.push_back(i);
        makeVector(i);
        v.pop_back();
    }
}
int main(){
    cin >> n >> m;

    makeVector(1);
    return 0;
}