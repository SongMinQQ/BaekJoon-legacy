#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int *arr = new int[n];
    int *sumArr = new int[n+1];
    sumArr[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sumArr[i+1] = arr[i] + sumArr[i];
    }
    int i, j;
    for(int k = 0; k < m; k++){
        cin >> i >> j;
        cout << sumArr[j] - sumArr[i-1] << '\n';
    }
    return 0;
}