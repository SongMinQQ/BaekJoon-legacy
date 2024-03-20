#include <bits/stdc++.h>
using namespace std;

int n, k, dollar, result = 0;
vector<int> v;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> dollar;
        v.push_back(dollar);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    for(int i : v){
        while(i <= k){
            if((k - i) >= 0){
            k -= i;
            result++;
            }
            else break;
        }
        if(k == 0) break;
    }
    cout << result;
}