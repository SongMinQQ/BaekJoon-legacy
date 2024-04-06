#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int result[500002], idx = 0, M, n, num;

int main(){
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> num;
        m.insert({num,num});
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(m.find(num) != m.end()){
            result[i] = 1;
        }
        else result[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << ' ';
    }
    return 0;
}