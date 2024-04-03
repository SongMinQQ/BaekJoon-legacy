#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> v2;
vector<int> result;
bool visited[9];
int n, m, num;

void print(int s){
    if(result.size() == m){
        for(int i : result){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < v.size(); i++){
        if(!visited[i]){
            visited[i] = 1;
            result.push_back(v[i]);
            print(i + 1);
            result.pop_back();
            visited[i] = 0;
        }
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