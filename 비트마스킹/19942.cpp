#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, mp, mf, ms, mv, minNum = 999999999, sum;

struct A{
    int mp, mf, ms, mv, cost;
}arr[16];
map<int, vector<vector<int>>> ret_v;
int main(){
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++){
        cin >> arr[i].mp >> arr[i].mf >> arr[i].ms >> arr[i].mv >> arr[i].cost;
    }
    //비트가 3개 이상 켜져 있는 수만

    for(int i = 0; i < (1 << n); i++){
        a = b = c = d = sum = 0;
        vector<int> v;
        for(int j = 0; j < n; j++)
        if(i & (1 << j)){
            v.push_back(j + 1);
            a += arr[j].mp;
            b += arr[j].mf;
            c += arr[j].ms;
            d += arr[j].mv;
            sum += arr[j].cost;
        }
        if(a >= mp && b >= mf && c >= ms && d >= mv){
            if(minNum >= sum){
                minNum = sum;
                ret_v[minNum].push_back(v);
            }
        }
    }
    if(minNum == 999999999) cout << -1 <<'\n';
    else {
        sort(ret_v[minNum].begin(),ret_v[minNum].end());
        cout << minNum <<'\n';
        for(int i : ret_v[minNum][0]){
            cout << i << ' ';
        }
    }
    return 0;
}