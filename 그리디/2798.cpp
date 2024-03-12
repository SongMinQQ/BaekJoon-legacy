#include <bits/stdc++.h>
using namespace std;

int n, m, card[102], result;

int main(){
    cin >> n >> m;
    int remainder = m;
    for(int i = 0; i < n; i++){
        cin >> card[i];
    }
    int closest = INT_MAX;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if((card[i]+card[j]+card[k]) % n <= remainder){
                    int sum = card[i] + card[j] + card[k];
                    if(sum <= m) { 
                        if(m - sum < closest) { 
                            closest = m - sum;
                            result = sum; 
                        }
                    }
                }
            }
        }
    }
    cout << result;
}