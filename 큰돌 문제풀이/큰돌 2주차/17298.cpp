#include <bits/stdc++.h>
using namespace std;

int n, num;
stack<int> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int *a = new int[n], *result = new int[n];
    fill(result,result + n, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(!s.empty() && a[s.top()] < a[i]){
            result[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << ' ';
    }
    return 0;
}