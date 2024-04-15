#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int num, n, result[500002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(m.find(num) != m.end()){
            m[num]++;
        }
        else{
            m.insert({num, 1});
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(m.find(num) != m.end()){
            result[i] = m[num];
        }
        else result[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << ' ';
    }
    return 0;
}