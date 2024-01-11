#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main(){
    fill(arr,arr+100,0);
    int a, b, c , result = 0, n, n2;
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        cin >> n >> n2;
        for(int j = n; j < n2; j++){
            arr[j]++;
        }
    }
    for(int i : arr){
        if(i == 1) result += a;
        else if (i == 2) result += b * 2;
        else if (i == 3) result += c * 3;
    }
    cout << result;
}