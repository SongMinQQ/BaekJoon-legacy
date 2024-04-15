#include <bits/stdc++.h>
using namespace std;

int num, sum = 0;
vector<int> v;

int main(){
    for(int i = 0; i < 5; i++){
        cin >> num;
        sum += num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    cout << sum / 5 << '\n' << v[2] ;
    return 0;
}