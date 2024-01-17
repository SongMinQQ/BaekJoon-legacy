#include <bits/stdc++.h>
using namespace std;

long long height, n, m;
vector<long long> v;

long long setting(long long start, long long end){
    if(start > end) return end;
    long long mid = (start + end) / 2;
    long long sum = 0;
    for(long long num : v){
        if(num > mid){
            sum += num - mid;
        }
    }
    if (sum >= m) {
        return setting(mid + 1, end);
    } else {
    return setting(start, mid - 1);
    }
}

int main(){
    long long max = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> height;
        max = (max < height) ? height : max;
        v.push_back(height);
    }
    cout << setting(0, max);
}