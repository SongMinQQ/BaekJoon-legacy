#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, num , sum = 0;
    cin >> n;
    if(n == 0){
        cout << '0';
        return 0;
    }
    int *arr = new int[n];

    int startIndex = round(n * 0.15);
    int endIndex = n - round(n * 0.15);


    for(int i = 0; i < n; i++){
        cin >> num;
        arr[i] = num;
    }
    sort(arr,arr+n);

    for(int i = startIndex; i < endIndex; i++){
        sum = sum + arr[i];
    }
    double result;
    if(n < 3){
        result = round(sum / n);
    }
    else{
        result = round(sum / (n - (startIndex * 2.0)));
    }
    cout << result; 
}