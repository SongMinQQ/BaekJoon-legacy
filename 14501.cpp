#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int n, a, b, sum = 0, sangdam = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    while(sangdam < n){
        sum += v[sangdam].second;
        sangdam += v[sangdam].first;

        if(sangdam >= n){ // 'sangdam'이 'n' 또는 그 이상이 되면 반복문을 빠져나감
            break;
        }
    }
    if(sangdam > n){
        sum -= v[n-1].second;
    }
    cout << sum;
}
