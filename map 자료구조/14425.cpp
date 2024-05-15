#include <bits/stdc++.h>
using namespace std;

map<string,int> a;
int n, m, result = 0;
string line;


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> line;
        a.insert({line, 0});
    }
    for(int i = 0 ; i < m; i++){
        cin >> line;
        if(a.find(line) != a.end()){
            result++;
        }
    }
    cout << result;
}