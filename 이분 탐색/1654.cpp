#include <bits/stdc++.h>
using namespace std;

long long k, n;
vector<long long> v;

long long length(long long start, long long end){
    long long result = 0;
    while(start <= end){
        cout << start << " : " << end << '\n';
        long long mid = (start + end) / 2;
        long long sum = 0;
        for(long long num : v){
            sum += num / mid;
        }
        if (sum >= n) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << start << " : " << end << '\n';

    return result;
}

int main(){
    long long max = 0, num;
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> num;
        v.push_back(num);
        max = num > max ? num : max;
    }
    cout << length(1, max);

    return 0;
}