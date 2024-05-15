#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    for(int j = n; j > 0; j--){
        for(int i = j; i > 0; i--){
            cout << '*';
        }
        cout << '\n';
    }
}