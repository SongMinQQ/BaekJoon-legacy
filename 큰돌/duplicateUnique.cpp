#include <bits/stdc++.h>
using namespace std;
// vector<int> v;
vector<int> v {1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9};
int main(){
    // for(int i = 1; i <=5; i++){
    //     v.push_back(i);
    //     v.push_back(i);// 1 1 2 2 3 3 4 4 5 5
    //     //1 2 3 4 5 3 4 4 5 5 
    // }
    // for(int i : v) cout << i << " ";
    // cout << '\n';
    // auto it = unique(v.begin(), v.end());//unique 함수는 중복되지 않는 iterator를 return
    // cout << it - v.begin() << '\n';
    // for(int i : v) cout << i << " ";
    // cout << '\n';
    auto it = unique(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    cout << '\n';
    return 0;
}