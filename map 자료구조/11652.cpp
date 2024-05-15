#include <bits/stdc++.h>
using namespace std;

int n;
map<long long, int> m;
long long num, maxNum = 0, cnt = 0;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(m.find(num) != m.end()){
            m[num]++;
        }
        else m.insert({num, 1});
    }

    for(auto i: m){
        if(cnt < i.second){
            cnt = i.second;
            maxNum = i.first;
        }
    }

    cout << maxNum;
    return 0;
}