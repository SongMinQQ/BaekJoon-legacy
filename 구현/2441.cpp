#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++){
        for(int j = n - i; j < n; j++){
            cout << ' ';
        }
        for(int j = i; j < n; j++){
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}