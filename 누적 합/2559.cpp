#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int *arr = new int[n];
    int *cumulativeArr = new int[n];
    int *sumArr = new int[n-m];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cumulativeArr[0] = arr[0];
    for (int i = 1; i < n; i++) {
        cumulativeArr[i] = cumulativeArr[i - 1] + arr[i];
    }

    int max = cumulativeArr[m-1];

    for(int j = 1; j < n - m + 1; j++){
        // cout << cumulativeArr[j + m - 1] - cumulativeArr[j - 1] << ' ';
        if((cumulativeArr[j + m - 1] - cumulativeArr[j - 1]) > max){
            max = cumulativeArr[j + m - 1] - cumulativeArr[j - 1];
        }
        // sumArr[j] = cumulativeArr[j + m - 1] - (j - m + 1 >= 0 ? cumulativeArr[j - 1] : 0);
    }

    // for(int i = 0; i < n-m+1; i++){
    //     if(sumArr[i] > max){
    //         max = sumArr[i];
    //     }
    // }
    cout << max;
    return 0;
}