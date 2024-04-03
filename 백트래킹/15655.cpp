#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> v2;
vector<int> result;
int n, m, num;

void print(int s){
    if(result.size() == m){
        for(int i : result){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = s; i < v.size(); i++){
        result.push_back(v[i]);
        print(i + 1);
        result.pop_back();
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    print(0);
    return 0;
}